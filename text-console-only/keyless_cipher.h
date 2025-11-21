#ifndef KEYLESS_CIPHER_H
#define KEYLESS_CIPHER_H

#include <string>

std::string caesarCipher(const std::string& text, int shift);
std::string caesarDecipher(const std::string& text, int shift);

#endif
