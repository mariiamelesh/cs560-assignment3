#include <iostream>
#include <string>
#include <windows.h>	

using CreateCaesar = void*(*)(int);
using CreateVigenere = void*(*)(const char*);
using EncryptDecrypt = char*(*)(void*, const char*);
using Destroy = void(*)(void*);
using Free = void(*)(char*);

int main() {
	//std::cout << "Hello world";
	return 0;
}