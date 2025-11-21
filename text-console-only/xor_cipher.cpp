#include "xor_cipher.h"

std::string xorCipher(const std::string& text, const std::string& key) {
    std::string result = text;
    for (size_t i = 0; i < text.size(); ++i) {
        result[i] ^= key[i % key.size()];
    }
    return result;
}
