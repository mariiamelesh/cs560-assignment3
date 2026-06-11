#pragma once
#include <string>
#include "abstractCipher.h"
#include "vigenereCipher.h"
#include <cctype>

VigenereCipher::VigenereCipher(const std::string& key) {
	this->key = key;
}

std::string VigenereCipher::encrypt(const std::string& text) {
	int index = 0;
	for (int i = 0; text[i] != '\0'; i++) {
		if (!std::isalpha(text[i]) {
			continue;
		}
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
		if (!std::isalpha(text[i])) {
			continue;
		}
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