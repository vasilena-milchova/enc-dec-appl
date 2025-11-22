#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include <string>

/**
 * Reads the entire contents of a file into a string.
 * 
 * @param filename The path to the file to be read.
 * @param data Output parameter; contains the contents of the file if read succeeds.
 * @return true if the file was successfully opened and read, false otherwise.
 */
bool readFile(const std::string& filename, std::string& data);

/**
 * Writes the given string data to a file.
 * 
 * @param filename The path to the file to be written.
 * @param data The data to write to the file.
 * @return true if the file was successfully written, false otherwise.
 */
bool writeFile(const std::string& filename, const std::string& data);

#endif
