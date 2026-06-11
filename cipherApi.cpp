#include "cipher_api.h"
#include "abstractCipher.h"
#include <cstring> 
#include <string>
#include "caesarCipher.h"
#include "vigenereCipher.h"

cipher_t cipherCreateCaesar(int key) {
    return new CaesarCipher(key);
}

cipher_t cipherCreateVigenere(const char* key) {
    return new VigenereCipher(std::string(key));
}

char* cipherEncrypt(cipher_t cipher, const char* text) {
	Cipher* objCipher = cipher;
	std::string temp = objCipher->encrypt(text);
	char* result = new char[temp.size() + 1];
    std::strcpy(result, temp.result());
	return result;
}

char* cipherDecrypt(cipher_t cipher, const char* text) {
	Cipher* objCipher = cipher;
	std::string temp = objCipher->decrypt(text);
	char* result = new char[temp.size() + 1];
    std::strcpy(result, temp.result());
	return result;
}

