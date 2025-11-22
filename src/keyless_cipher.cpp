#include "keyless_cipher.h"

// Each character is shifted by 'shift' positions modulo 256.
// This allows wrapping around for the extended ASCII range (0-255).
std::string caesarCipher(const std::string& text, int shift) {
    std::string result = text;
    for (char& c : result) {
        c = static_cast<char>((c + shift) % 256);
    }
    return result;
}

// Each character is shifted back by 'shift' positions modulo 256.
// The addition of 256 ensures no negative values before modulo operation.
std::string caesarDecipher(const std::string& text, int shift) {
    std::string result = text;
    for (char& c : result) {
        c = static_cast<char>((c - shift + 256) % 256);
    }
    return result;
}
