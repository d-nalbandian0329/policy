#include "../header/AsciiFileReaderPolicy.h"

namespace tks {
	namespace io {
		auto AsciiFileReaderPolicy::readDataFromFile(const std::string& file_path)
			-> std::vector<std::string> {

			std::ifstream ifs;

			ifs.exceptions(std::ifstream::failbit | std::ifstream::badbit);

			std::vector<std::string> ret {};
			int line = 0;

			try {
				ifs.open(file_path, std::ios::in);

				std::string buff;

				while (std::getline(ifs, buff))
					++line, ret.push_back(buff);
			}
			catch (std::ifstream::failure& ex) {
				if (!ifs.eof()) {
					std::cerr << "Error occurs at line " << line << "." << std::endl;
					std::cerr << ex.what() << std::endl;
				}
			}
			catch (std::exception& ex) {
				std::cerr << "Error occurs at line " << line << "." << std::endl;
				std::cerr << ex.what() << std::endl;
			}

			return ret;
		}
	}
}
