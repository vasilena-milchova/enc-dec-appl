#include "xor_cipher.h"

// The same function works for both encryption and decryption because XOR is its own inverse.
std::string xorCipher(const std::string& text, const std::string& key) {
    std::string result = text;
    for (size_t i = 0; i < text.size(); ++i) {
        result[i] ^= key[i % key.size()];
    }
    return result;
}

bool isKeyValid(const std::string& text, const std::string& key) {
    return key.size() < text.size();
}
