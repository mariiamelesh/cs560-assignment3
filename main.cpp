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
	
	int running = 1;
	while (running) {
		int choice;
		std::cout << "choose cipher: 1 - caesar 2 - vigenere\n0 - exit\n> ";
		std::cin >> choice;
		void* cipher = nullptr;
		switch (choice) {
			case 0: {
				running = 0;
				continue;
			}
			case 1: {
				int key;
				std::cout << "write your key\n> ";
				std::cin.ignore(10000, '\n');
				std::cin >> key;
				if (std::cin.fail()) {
					std::cout << "wrong input XD";
					return 1;
				}
				void* caesar = createCaesar(key);
				cipher = caesar;
				break;
			}
			case 2: {
				std::string key;
				std::cout << "write your key\n> ";
				std::cin.ignore(10000, '\n');
				std::getline(std::cin, key);
				if (std::cin.fail()) {
					std::cout << "wrong input XD";
					return 1;
				}
				void* vigenere = createVigenere(key.c_str());
				cipher = vigenere;
				break;
			}
			default:
				std::cout << "invalid input";
				break;
		}
		if (running == 0) {
			break;
		}
		std::string text;
		std::cout << "write your text\n> ";
		std::cin.ignore();
        std::getline(std::cin, text);
		int choice1;
		std::cout << "1 - encrypt, 2 - decrypt\n> ";
		std::cin >> choice1;
		char* result = nullptr;
		switch (choice1) {
			case 1:
				result = cipherEncrypt(cipher, text.c_str());
				std::cout << "encrypted text: " << result << std::endl;
				break;
			case 2:
				result = cipherDecrypt(cipher, text.c_str());
				std::cout << "decrypted text: " << result << std::endl;
				break;
			default:
				std::cout << "invalid input";
				break;
		}
		if (cipher!=nullptr) {
			cipherDestroy(cipher);
		}
		if (result!=nullptr) {
			cipherFree(result);
		}
	}
	FreeLibrary(lib);
	return 0;
}