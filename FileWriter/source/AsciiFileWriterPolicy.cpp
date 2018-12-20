#include "AsciiFileWriterPolicy.h"

namespace tks {
	namespace io {
		auto AsciiFileWriterPolicy::writeDataToFile(
				const std::string& file_path, const std::vector<std::string>& container) -> bool {

			std::ofstream ofs;

			ofs.exceptions(std::ofstream::failbit | std::ofstream::badbit);

			try {
				ofs.open(file_path.c_str(), std::ios::out | std::ios::trunc);

				for(std::size_t i = 0; i < container.size(); ++i)
					ofs << container[i] << std::endl;

				return true;
			}
			catch (std::exception& ex) {
				std::cerr << ex.what() << std::endl;
			}

			return false;
		}
	}
}

