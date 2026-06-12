#include <string>
#include "abstractCipher.h"
#include "affineCipher.h"
#include <cctype>

AffineCipher::AffineCipher(int a, int b) {
	this->a = a;
	this->b =b;
}

std::string AffineCipher::encrypt(const std::string& text) {
	std::string temp = text;
	for (int i = 0; temp[i] != '\0'; i++) {
		if (!std::isalpha(temp[i])) {
			continue;
		}
		int	shiftedPosition = a * temp[i] + b;
		temp[i] = shiftedPosition % 26;
	}
	return temp;
}

std::string AffineCipher::decrypt(const std::string& text) {
	std::string temp = text;
	for (int i = 0; temp[i] != '\0'; i++) {
		if (!std::isalpha(temp[i])) {
			continue;
		}
		int reverse;
		a = a % 26;
		for (int x = 1; x < 26; x++) {
			if ((a * x) % 26 == 1) {
				reverse = x; 
			}
		}
		int shiftedPosition = (temp[i] - b) * reverse;
		temp[i] = shiftedPosition % 26;
	}
	return temp;
}