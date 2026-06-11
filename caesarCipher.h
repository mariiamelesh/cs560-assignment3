#pragma once
#include <string>
#include "abstractCipher.h"

class CaesarCipher : public Cipher {
	int key_;
	public:
	CaesarCipher(int key);
	std::string encrypt(const std::string& text) override;
	std::string decrypt(const std::string& text) override;
};