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
		
		char a;
		if (std::isupper(temp[i])) {
			a = 'A';
		} else {
			a = 'a';
		}
		int shift = key_[index] - a;
		int	shiftedPosition = temp[i] - a + shift;
		temp[i] = shiftedPosition % 26 + a;
		
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
		
		char a;
		if (std::isupper(temp[i])) {
			a = 'A';
		} else {
			a = 'a';
		}
		int shift = key_[index] - a;
		int	shiftedPosition = temp[i] - a + 26 - shift;
		temp[i] = shiftedPosition % 26 + a;
		
		if (index == key_.size() - 1) {
			index = 0;
		} else {
			index++;
		}
	}
	return temp;
}