#pragma once
#include <string>
#include "caesarCipher.h"
#include "abstractCipher.h"
#include <cctype>

CaesarCipher::CaesarCipher(int key) {
	this->key = key;
}

std::string CaesarCipher::encrypt(const std::string& text) {
	for (int i = 0; text[i] != '\0'; i++) {
		if (!std::isalpha(text[i]) {
			continue;
		}
		text[i] = text[i] + key;
	}
	return text;
}

std::string CaesarCipher::decrypt(const std::string& text) {
	for (int i = 0; text[i] != '\0'; i++) {
		if (!std::isalpha(text[i]) {
			continue;
		}
		text[i] = text[i] - key;
	}
	return text;
}