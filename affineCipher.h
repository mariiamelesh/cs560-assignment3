#pragma once
#include <string>
#include "abstractCipher.h"

class AffineCipher : public Cipher {
	int a;
	int b;
	public:
	AffineCipher(int a, int b);
	std::string encrypt(const std::string& text) override;
	std::string decrypt(const std::string& text) override;
};