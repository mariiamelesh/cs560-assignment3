#include "cipherApi.h"
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


cipher_t cipherCreateAffine(int a, int b) {
    return new AffineCipher(a, b);
}

char* cipherEncrypt(cipher_t cipher, const char* text) {
	Cipher* objCipher = static_cast<Cipher*>(cipher);
	std::string temp = objCipher->encrypt(text);
	char* result = new char[temp.size() + 1];
    std::strcpy(result, temp.c_str());
	return result;
}

char* cipherDecrypt(cipher_t cipher, const char* text) {
	Cipher* objCipher = static_cast<Cipher*>(cipher);
	std::string temp = objCipher->decrypt(text);
	char* result = new char[temp.size() + 1];
    std::strcpy(result, temp.c_str());
	return result;
}

void cipherDestroy(cipher_t cipher) {
	delete static_cast<Cipher*>(cipher);
}

void cipherFree(char* str) {
	delete[] str;
}