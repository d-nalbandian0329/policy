#ifndef _ASCII_FILE_WRITER_POLICY_
#define _ASCII_FILE_WRITER_POLICY_

#include <iostream>
#include <fstream>
#include <vector>
#include <string>


namespace tks {
	namespace io {
		class AsciiFileWriterPolicy {
		public:
			static auto writeDataToFile(
					const std::vector<std::string>& container, const std::string& file_path) -> bool;	
		};
	}
}

#endif // _ASCII_FILE_WRITER_POLICY_

