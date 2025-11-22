#ifndef UTILS_H
#define UTILS_H

#include <string>

/**
 * @file utils.h
 * @brief Utility functions for byte/hex conversions and displaying messages.
 *
 * This header declares functions to convert binary data to hexadecimal string representation,
 * convert hexadecimal strings back to binary data, and display message dialogs to the user.
 */

std::string bytesToHex(const std::string& data);
std::string hexToBytes(const std::string& hex);
void show_message(const char* msg);

#endif // UTILS_H
