#ifndef _BINARY_FILE_READER_POLICY_
#define _BINARY_FILE_READER_POLICY_

#include <iostream>
#include <fstream>
#include <utility>
#include <memory>
#include <string>


namespace tks {
	namespace io {
		// バイナリファイルの中身を読み込むためのクラス
		class BinaryFileReaderPolicy {
		public:
			// @brief  : バイナリファイルを読み込んで結果を返す関数
			// @Para   : 読み込み対象ファイルのパス
			// @Return : 読み込み結果を格納した配列へのスマートポインタと要素数のstd::pair
			static auto readDataFromFile(const std::string& file_path)
				-> std::pair<std::unique_ptr<char[]>, std::size_t>;
		};
	}
}

#endif // _BINARY_FILE_READER_POLICY_

