#ifndef OTP_H
#define OTP_H

#include <string>

std::string otpEncrypt(const std::string& text, std::string& keyOut);
std::string otpDecrypt(const std::string& encrypted, const std::string& key);

#endif
