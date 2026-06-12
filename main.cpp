#include <iostream>
#include <string>
#include <windows.h>	

using CreateCaesar = void*(*)(int);
using CreateVigenere = void*(*)(const char*);
using Encrypt = char*(*)(void*, const char*);
using Decrypt = char*(*)(void*, const char*);
using Destroy = void(*)(void*);
using Free = void(*)(char*);

void console(HINSTANCE lib) {
	int running = 1;
	while (running) {
		int choice;
		std::cout << "choose cipher: 1 - caesar 2 - vigenere\n> ";
		std::cin >> choice;
		switch {
			case 1:
				int key;
				std::string text;
				std::cout << "write your key\n> ";
				std::cin >> key;
				void* caesar = createCaesar(key);
				std::cout << "write your text\n> ";
				std::cin >> text;
				char* encrypted = cipherEncrypt(caesar, text.c_str());
				break;
		}
	}
}

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
	
	console(lib);

	return 0;
}