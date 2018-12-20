#ifndef _ASCII_FILE_READER_POLICY_
#define _ASCII_FILE_READER_POLICY_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>


namespace tks {
	namespace io {
		// ASCIIファイルを読み込むためのクラス
		class AsciiFileReaderPolicy {
		public:
			// @brief  : ASCIIファイルを読みこんで結果を返す
			// @Para   : 読み込み対象のファイルパス
			// @Return : 読み込み結果を格納したstd::vector
			static auto readDataFromFile(const std::string& file_path) -> std::vector<std::string>;
		};
	}
}

#endif //_ASCII_FILE_READER_POLICY_
