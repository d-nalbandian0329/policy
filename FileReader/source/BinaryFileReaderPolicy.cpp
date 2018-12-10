#include "../header/BinaryFileReaderPolicy.h"

auto BinaryFileReaderPolicy::readDataFromFile(const std::string& file_path)
	-> std::pair<std::unique_ptr<char[]>, std::size_t> {

	std::ifstream ifs;

	ifs.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	std::unique_ptr<char[]> byte_data {};
	std::size_t file_size {};

	try {
		ifs.open(file_path, std::ios::in | std::ios::binary);

		// ファイルサイズの確認
		ifs.seekg(0, std::ios::end);
		file_size = ifs.tellg();
		ifs.seekg(0, std::ios::beg);

		byte_data.reset(new char[file_size]);

		ifs.read(byte_data.get(), file_size);
	}
	catch (std::ifstream::failure& ex) {
		if (!ifs.eof()) {
			std::cerr << ex.what() << std::endl;
		}
	}
	catch (std::exception& ex) {
		std::cerr << ex.what() << std::endl;
	}

	return std::make_pair(std::move(byte_data), file_size);
}

