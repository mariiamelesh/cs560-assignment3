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
	
	CreateCaesar createCaesar = (CreateCaesar)GetProcAddress(hLib, "cipherCreateCaesar");
    CreateVigenere createVigenere = (CreateVigenere)GetProcAddress(hLib, "cipherCreateVigenere");
    Encrypt cipherEncrypt = (Encrypt)GetProcAddress(hLib, "cipherEncrypt");
    Decrypt cipherDecrypt = (Decrypt)GetProcAddress(hLib, "cipherDecrypt");
    Destroy cipherDestroy = (Destroy)GetProcAddress(hLib, "cipherDestroy");
    Free cipherFree = (Free)GetProcAddress(hLib, "cipherFree");
	//std::cout << "Hello world";
	return 0;
}