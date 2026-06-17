#include <iostream>
#include <string>
#include <cassert>
#include <windows.h>	

#include "abstractCipher.h"
#include "caesarCipher.h"
#include "vigenereCipher.h"
#include "affineCipher.h"

using CreateCaesar = void*(*)(int);
using CreateVigenere = void*(*)(const char*);
using CreateAffine = void*(*)(int, int);
using Encrypt = char*(*)(void*, const char*);
using Decrypt = char*(*)(void*, const char*);
using Destroy = void(*)(void*);
using Free = void(*)(char*);

int main() {
	HINSTANCE lib = LoadLibrary(TEXT("cipher.dll"));
    if (!lib) {
        return 1;
    }
	
	CreateCaesar createCaesar = (CreateCaesar)GetProcAddress(lib, "cipherCreateCaesar");
    CreateVigenere createVigenere = (CreateVigenere)GetProcAddress(lib, "cipherCreateVigenere");
	CreateAffine createAffine = (CreateAffine)GetProcAddress(lib, "cipherCreateAffine");
    Encrypt cipherEncrypt = (Encrypt)GetProcAddress(lib, "cipherEncrypt");
    Decrypt cipherDecrypt = (Decrypt)GetProcAddress(lib, "cipherDecrypt");
    Destroy cipherDestroy = (Destroy)GetProcAddress(lib, "cipherDestroy");
    Free cipherFree = (Free)GetProcAddress(lib, "cipherFree");
	
    CaesarCipher cipher(3);
    assert(cipherEncrypt(cipher, "Hello") == "Khoor");
    assert(cipherDecrypt(cipher, "Khoor") == "Hello");
	std::cout << "simple caesar encrypt/decrypt passed";
    
    assert(cipherEncrypt(cipher, "Hello world!") == "Khoor zruog!");
    assert(cipherDecrypt(cipher, "Khoor zruog!") == "Hello World!");
    std::cout << " caesar encrypt/decrypt with symbols passed";

    CaesarCipher bigKeyCipher(30);
    assert(cipherEncrypt(bigKeyCipher, "ABC") == "EFG");
    assert(cipherDecrypt(bigKeyCipher, "EFG") == "ABC");
    std::cout << " caesar encrypt/decrypt edge case passed";
	
    VigenereCipher cipher("key");
 
    assert(cipherEncrypt(cipher, "Hello World!") == "Rijvs Uyvjn!");
    assert(cipherDecrypt(cipher, "Rijvs Uyvjn!") == "Hello World!");
    std::cout << "vigenere encrypt/decrypt with symbols passed";

    VigenereCipher upperKeyCipher("KeY");
    assert(cipherEncrypt(upperKeyCipher, "Hello") == "Rijvs");
	std::cout << "vigenere encrypt/decrypt with different case key passed";

	AffineCipher cipher(5, 8);
	assert(cipherEncrypt(cipher, "Hello world!") == "Rclla oaplx!"); 
    assert(cipherDecrypt(cipher, "Rclla") == "Hello");
    std::cout << "affine encrypt/decrypt key passed";
    
    return 0;
}