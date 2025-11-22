#ifndef XOR_CIPHER_H
#define XOR_CIPHER_H

#include <string>

/**
 * Applies XOR encryption or decryption to the input text using a repeating key.
 *
 * @param text The input string to be encrypted or decrypted.
 * @param key The encryption key, repeated cyclically if shorter than 'text'.
 * @return The result string after XOR operation with the key.
 */
std::string xorCipher(const std::string& text, const std::string& key);

/**
 * Ensures the key is shorter than the text to allow cycling of the key.
 *
 * @param text The input string to be encrypted or decrypted.
 * @param key The encryption key.
 * @return true if key length is less than text length, false otherwise.
 */
bool isKeyValid(const std::string& text, const std::string& key);

#endif
