#pragma once
#include <string>
#include "vigenereCipher.h"

VigenereCipher::VigenereCipher(const std::string& key) {
	this->key = key;
}

std::string VigenereCipher::encrypt(const std::string& text) {
	int index = 0;
	for (int i = 0; text[i] != '\0'; i++) {
		int shift = key[index] - 'a';
		text[i] = text[i] + shift;
		if (index == key.size() - 1) {
			index = 0;
		} else {
			index++;
		}
	}
	return text;
}

std::string VigenereCipher::decrypt(const std::string& text) {
	int index = 0;
	for (int i = 0; text[i] != '\0'; i++) {
		int shift = key[index] - 'a';
		text[i] = text[i] - shift;
		if (index == key.size() - 1) {
			index = 0;
		} else {
			index++;
		}
	}
	return text;
}