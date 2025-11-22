#include "file_utils.h"
#include <fstream>

bool readFile(const std::string& filename, std::string& data) {
    std::ifstream file(filename, std::ios::binary);
    if (!file) return false;
    data.assign((std::istreambuf_iterator<char>(file)),
                std::istreambuf_iterator<char>());
    return true;
}

bool writeFile(const std::string& filename, const std::string& data) {
    std::ofstream file(filename, std::ios::binary);
    if (!file) return false;
    file.write(data.data(), data.size());
    return true;
}
