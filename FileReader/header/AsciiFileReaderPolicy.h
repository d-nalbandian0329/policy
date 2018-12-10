#ifndef _ASCII_FILE_READER_POLICY_
#define _ASCII_FILE_READER_POLICY_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// Used for reading ascii file.
class AsciiFileReaderPolicy {
public:
    static auto readDataFromFile(const std::string& file_path) -> std::vector<std::string>;
};

#endif //_ASCII_FILE_READER_POLICY_
