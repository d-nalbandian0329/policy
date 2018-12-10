#ifndef _ASCII_FILE_WRITER_POLICY_
#define _ASCII_FILE_WRITER_POLICY_

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class AsciiFileWriterPolicy {
public:
	static auto writeDataToFile(
			const std::string& file_path, const std::vector<std::string>& container) -> bool;	
};

#endif // _ASCII_FILE_WRITER_POLICY_

