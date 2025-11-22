#ifndef OTP_H
#define OTP_H

#include <string>

/**
 * Encrypts plaintext using a one-time pad cipher.
 *
 * @param plaintext The input string to be encrypted.
 * @param keyOut Output parameter that receives the random key used for encryption.
 * @return Encrypted ciphertext string.
 */
std::string otpEncrypt(const std::string& plaintext, std::string& keyOut);

/**
 * Decrypts ciphertext that was encrypted with a one-time pad.
 *
 * @param ciphertext The encrypted string to be decrypted.
 * @param key The one-time pad key that was used for encryption.
 * @return Decrypted plaintext string.
 */
std::string otpDecrypt(const std::string& ciphertext, const std::string& key);

#endif
