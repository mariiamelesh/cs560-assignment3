#include <string>
#include "abstractCipher.h"
#include "vigenereCipher.h"
#include <cctype>

VigenereCipher::VigenereCipher(const std::string& key) {
	this->key_ = std::tolower(key);
}

std::string VigenereCipher::encrypt(const std::string& text) {
	std::string temp = text;
	int index = 0;
	for (int i = 0; temp[i] != '\0'; i++) {
		if (!std::isalpha(temp[i])) {
			continue;
		}
		int shift = key[index] - 'a';
		temp[i] = temp[i] + shift;
		if (index == key.size() - 1) {
			index = 0;
		} else {
			index++;
		}
	}
	return temp;
}

std::string VigenereCipher::decrypt(const std::string& text) {
	std::string temp = text;
	int index = 0;
	for (int i = 0; temp[i] != '\0'; i++) {
		if (!std::isalpha(temp[i])) {
			continue;
		}
		int shift = key[index] - 'a';
		temp[i] = temp[i] - shift;
		if (index == key.size() - 1) {
			index = 0;
		} else {
			index++;
		}
	}
	return temp;
}