#pragma once
#include <string>
#include "abstractCipher.h"

class VigenereCipher : public Cipher {
	std::string key_;
	public:
	VigenereCipher(const std::string& key);
	std::string encrypt(const std::string& text) override;
	std::string decrypt(const std::string& text) override;
};