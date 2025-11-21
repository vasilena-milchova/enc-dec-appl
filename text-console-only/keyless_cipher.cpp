#include "keyless_cipher.h"

std::string caesarCipher(const std::string& text, int shift) {
    std::string result = text;
    for (char& c : result) {
        c = static_cast<char>((c + shift) % 256);
    }
    return result;
}

std::string caesarDecipher(const std::string& text, int shift) {
    std::string result = text;
    for (char& c : result) {
        c = static_cast<char>((c - shift + 256) % 256);
    }
    return result;
}
