#pragma once
#include <string>

class VigenereCipher : public Cipher {
	std::string key_;
	public:
	VigenereCipher(const std::string& key);
	std::string encrypt(const std::string& text) override;
	std::string decrypt(const std::string& text) override;
};