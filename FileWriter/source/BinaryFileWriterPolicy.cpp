#include "../header/BinaryFileWriterPolicy.h"


auto BinaryFileWriterPolicy::writeDataToFile(const std::string& file_path,
		std::unique_ptr<char[]> byte_data, std::size_t total_size) -> bool {

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

