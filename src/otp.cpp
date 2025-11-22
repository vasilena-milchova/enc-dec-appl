#include "otp.h"
#include <random>


// Generates a random key of the same length as plaintext.
// XORs each byte of plaintext with a random byte key.
// Outputs the key via keyOut for later decryption.
std::string otpEncrypt(const std::string& plaintext, std::string& keyOut) {
    std::string ciphertext = plaintext;
    
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<unsigned char> dis(0, 255);
    
    keyOut.resize(plaintext.size());
    for (size_t i = 0; i < plaintext.size(); ++i) {
        keyOut[i] = dis(gen);
        ciphertext[i] ^= keyOut[i];
    }
    
    return ciphertext;
}

// XORs each byte of ciphertext with the corresponding key byte.
// Returns plaintext if key length matches ciphertext length, otherwise returns ciphertext unchanged.
std::string otpDecrypt(const std::string& ciphertext, const std::string& key) {
    std::string plaintext = ciphertext;
    
    if (key.size() != ciphertext.size()) {
        return plaintext;
    }
    
    for (size_t i = 0; i < ciphertext.size(); ++i) {
        plaintext[i] ^= key[i];
    }
    
    return plaintext;
}
