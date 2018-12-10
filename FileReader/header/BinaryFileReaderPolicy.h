#ifndef _BINARY_FILE_READER_POLICY_
#define _BINARY_FILE_READER_POLICY_

#include <iostream>
#include <fstream>
#include <utility>
#include <memory>
#include <string>

class BinaryFileReaderPolicy {
public:
    static auto readDataFromFile(const std::string& file_path)
		-> std::pair<std::unique_ptr<char[]>, std::size_t>;
};

#endif // _BINARY_FILE_READER_POLICY_

