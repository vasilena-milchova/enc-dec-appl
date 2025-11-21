#include <iostream>
#include <string>
#include "otp.h"
#include "xor_cipher.h"
#include "keyless_cipher.h"

int main() {
    std::cout << "Choose encryption:\n1. XOR Cipher\n2. One-Time Pad\n3. Caesar Cipher\n";
    int choice;
    std::cin >> choice;
    std::cin.ignore(); // Clear newline

    std::cout << "Enter text: ";
    std::string text;
    std::getline(std::cin, text);

    if (choice == 1) {
        std::cout << "Enter XOR key: ";
        std::string key;
        std::getline(std::cin, key);
        std::string encrypted = xorCipher(text, key);
        std::string decrypted = xorCipher(encrypted, key);
        std::cout << "Encrypted: " << encrypted << "\n";
        std::cout << "Decrypted: " << decrypted << "\n";
    } else if (choice == 2) {
        std::string otpKey;
        std::string encrypted = otpEncrypt(text, otpKey);
        std::string decrypted = otpDecrypt(encrypted, otpKey);
        std::cout << "Encrypted: " << encrypted << "\n";
        std::cout << "OTP Key: " << otpKey << "\n";
        std::cout << "Decrypted: " << decrypted << "\n";
    } else if (choice == 3) {
        int shift = 13; // example fixed shift
        std::string encrypted = caesarCipher(text, shift);
        std::string decrypted = caesarDecipher(encrypted, shift);
        std::cout << "Encrypted: " << encrypted << "\n";
        std::cout << "Decrypted: " << decrypted << "\n";
    } else {
        std::cout << "Invalid choice.\n";
    }
    return 0;
}
