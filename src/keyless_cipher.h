#ifndef KEYLESS_CIPHER_H
#define KEYLESS_CIPHER_H

#include <string>

/**
 * Applies a Caesar cipher shift to the input text.
 *
 * @param text The input string to be ciphered.
 * @param shift The number by which to shift each character.
 * @return The result string.
 */
std::string caesarCipher(const std::string& text, int shift);

/**
 * Reverses the Caesar cipher shift to retrieve the original text.
 *
 * @param text The ciphered string to be deciphered.
 * @param shift The number by which each character was originally shifted.
 * @return The deciphered original string.
 */
std::string caesarDecipher(const std::string& text, int shift);

#endif
