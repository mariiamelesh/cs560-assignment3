#include <string>
#include "abstractCipher.h"
#include "vigenereCipher.h"
#include <cctype>

VigenereCipher::VigenereCipher(const std::string& key) {
	this->key_ = key;
	for (int i = 0; i < this->key_.size(); i++) {
        this->key_[i] = std::tolower(this->key_[i]);
    }
}

std::string VigenereCipher::encrypt(const std::string& text) {
	std::string temp = text;
	int index = 0;
	for (int i = 0; temp[i] != '\0'; i++) {
		if (!std::isalpha(temp[i])) {
			continue;
		}
		int shift = key_[index] - 'a';
		temp[i] = temp[i] + shift;
		if (index == key_.size() - 1) {
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
		int shift = key_[index] - 'a';
		temp[i] = temp[i] - shift;
		if (index == key_.size() - 1) {
			index = 0;
		} else {
			index++;
		}
	}
	return temp;
}