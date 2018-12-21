#include "BinaryFileWriterPolicy.h"

namespace tks {
	namespace io {
		auto BinaryFileWriterPolicy::writeDataToFile(std::unique_ptr<char[]> byte_data,
														std::size_t total_size, const std::string& file_path) -> bool {

			std::ofstream ofs;

			ofs.exceptions(std::ofstream::failbit | std::ofstream::badbit);

			try {
				ofs.open(file_path.c_str(), std::ios::out | std::ios::binary | std::ios::trunc);

				ofs.write(byte_data.get(), total_size);

				return true;
			}
			catch(std::exception& ex) {
				std::cerr << ex.what() << std::endl;
			}

			return false;
		}
	}
}

