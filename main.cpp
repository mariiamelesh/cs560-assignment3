#include <iostream>
#include <string>
#include <windows.h>	

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
	std::cout << "cipherCreateCaesar function pointer: " << (void*)createCaesar << std::endl;
    CreateVigenere createVigenere = (CreateVigenere)GetProcAddress(lib, "cipherCreateVigenere");
	std::cout << "cipherCreateVigenere function pointer: " << (void*)createVigenere << std::endl;
	CreateAffine createAffine = (CreateAffine)GetProcAddress(lib, "cipherCreateAffine");
	std::cout << "cipherCreateAffine function pointer: " << (void*)createAffine << std::endl;
    Encrypt cipherEncrypt = (Encrypt)GetProcAddress(lib, "cipherEncrypt");
	std::cout << "cipherEncrypt function pointer: " << (void*)cipherEncrypt << std::endl;
    Decrypt cipherDecrypt = (Decrypt)GetProcAddress(lib, "cipherDecrypt");
	std::cout << "cipherDecrypt function pointer: " << (void*)cipherDecrypt << std::endl;
    Destroy cipherDestroy = (Destroy)GetProcAddress(lib, "cipherDestroy");
	std::cout << "cipherDestroy function pointer: " << (void*)cipherDestroy << std::endl;
    Free cipherFree = (Free)GetProcAddress(lib, "cipherFree");
	std::cout << "cipherFree function pointer: " << (void*)cipherFree << '\n' << std::endl;
	int running = 1;
	while (running) {
		int choice;
		std::cout << "\nchoose cipher: 1 - caesar 2 - vigenere 3 - affine\n0 - exit\n> ";
		std::cin >> choice;
		void* cipher = nullptr;
		switch (choice) {
			case 0: {
				running = 0;
				continue;
			}
			case 1: {
				int key;
				std::cin.ignore(10000, '\n');
				std::cout << "write your key\n> ";
				std::cin >> key;
				if (std::cin.fail() || key < 0) {
                    std::cout << "wrong input XD";
                    return 1;
                } 
				std::cin.ignore(10000, '\n');
				void* caesar = createCaesar(key);
				cipher = caesar;
				break;
			}
			case 2: {
				std::string key;
				std::cin.ignore(10000, '\n');
				std::cout << "write your key\n> ";
				std::getline(std::cin, key);
				for (int i = 0; i < key.size(); i++) {
					if (!std::isalpha(key[i])) {
						std::cout << "wrong input XD";
						return 1;
					}
				}
				void* vigenere = createVigenere(key.c_str());
				cipher = vigenere;
				break;
			}
			case 3: {
				int a, b;
				std::cout << "write a coefficient\n> ";
				std::cin.ignore();
				std::cin >> a;
				if (std::cin.fail()) {
					std::cout << "wrong input XD";
					return 1;
				}
				std::cout << "write b coefficient\n> ";
				std::cin.ignore();
				std::cin >> b;
				
				if (std::cin.fail()) {
					std::cout << "wrong input XD";
					return 1;
				}
				void* affine = createAffine(a,b);
				cipher = affine;
				break;
			}
			default:
				std::cout << "invalid input\n";
				continue;
			}
		if (running == 0) {
			break;
		}
		std::string text;
		//std::cin.ignore(10, '\n');
		std::cout << "write your text\n> ";
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