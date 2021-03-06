#ifndef _BINARY_FILE_WRITER_POLICY_
#define _BINARY_FILE_WRITER_POLICY_

#include <iostream>
#include <fstream>
#include <memory>
#include <string>


namespace tks {
	namespace io {
		class BinaryFileWriterPolicy {
		public:
			static auto writeDataToFile(std::unique_ptr<char[]> byte_data,
											std::size_t total_size, const std::string& file_path) -> bool;
		};
	}
}
#endif // _BINARY_FILE_WRITER_POLICY_

