#include <iostream>
#include <string>
#include <windows.h>	

using CreateCaesar = void*(*)(int);
using CreateVigenere = void*(*)(const char*);
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
    Encrypt cipherEncrypt = (Encrypt)GetProcAddress(lib, "cipherEncrypt");
    Decrypt cipherDecrypt = (Decrypt)GetProcAddress(lib, "cipherDecrypt");
    Destroy cipherDestroy = (Destroy)GetProcAddress(lib, "cipherDestroy");
    Free cipherFree = (Free)GetProcAddress(lib, "cipherFree");
	//std::cout << "Hello world";
	return 0;
}