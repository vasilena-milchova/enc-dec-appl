#include "utils.h"
#include <sstream>
#include <iomanip>
#include <FL/fl_ask.H>


// Each byte is represented as two hexadecimal characters, padded with leading zero if necessary. Uses a stringstream to format the output.
std::string bytesToHex(const std::string& data) {
    std::stringstream ss;
    for (unsigned char c : data) {
        ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(c);
    }
    return ss.str();
}

// The hexadecimal input is parsed two characters at a time and converted.
std::string hexToBytes(const std::string& hex) {
    std::string bytes;
    for (size_t i = 0; i < hex.length(); i += 2) {
        std::string byteString = hex.substr(i, 2);
        char byte = (char) strtol(byteString.c_str(), nullptr, 16);
        bytes.push_back(byte);
    }
    return bytes;
}

void show_message(const char* msg) {
    fl_message("%s", msg);
}
