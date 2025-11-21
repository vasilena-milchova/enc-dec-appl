#include "otp.h"
#include <random>

std::string otpEncrypt(const std::string& text, std::string& keyOut) {
    std::string encrypted = text;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 255);
    keyOut.resize(text.size());
    for (size_t i = 0; i < text.size(); ++i) {
        keyOut[i] = static_cast<char>(dis(gen));
        encrypted[i] ^= keyOut[i];
    }
    return encrypted;
}

std::string otpDecrypt(const std::string& encrypted, const std::string& key) {
    std::string decrypted = encrypted;
    for (size_t i = 0; i < encrypted.size(); ++i) {
        decrypted[i] ^= key[i];
    }
    return decrypted;
}
