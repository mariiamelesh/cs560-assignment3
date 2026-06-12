#include <string>
#include "abstractCipher.h"
#include "affineCipher.h"
#include <cctype>

AffineCipher::AffineCipher(int a, int b) {
	this->a = a;
	this->b =b;
}