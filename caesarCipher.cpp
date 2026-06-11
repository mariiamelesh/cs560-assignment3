#include <string>
#include "caesarCipher.h"
#include "abstractCipher.h"
#include <cctype>

CaesarCipher::CaesarCipher(int key) {
	this->key = key;
}

std::string CaesarCipher::encrypt(const std::string& text) {
	std::string temp = text;
	for (int i = 0; temp[i] != '\0'; i++) {
		if (!std::isalpha(temp[i]) {
			continue;
		}
		text[i] = temp[i] + key;
	}
	return temp;
}

std::string CaesarCipher::decrypt(const std::string& text) {
	std::string temp = text;
	for (int i = 0; temp[i] != '\0'; i++) {
		if (!std::isalpha(temp[i]) {
			continue;
		}
		temp[i] = temp[i] - key;
	}
	return temp;
}