#ifndef _FILE_READER_
#define _FILE_READER_

#include <string>
#include <utility>
#include <type_traits>

#include "AsciiFileReaderPolicy.h"

namespace tks {
	namespace io {
			// 実装部
		struct has_readDataFromFile_impl {
			template <class T>
			static auto check(T*) -> decltype(T::readDataFromFile(""), std::true_type());

			template <class T>
			static auto check(...) -> std::false_type;
		};

		// readDataFromFileという名前のクラスを持っているかを判定するメタ関数
		template <class T>
		class has_readDataFromFile : public decltype(has_readDataFromFile_impl::check<T>(nullptr)) {
		};



		// ファイル読み込みを行うポリシークラス
		// 実際の処理はテンプレート引数に指定されたクラスに丸投げする
		template <class FileReaderPolicy = AsciiFileReaderPolicy,
					typename std::enable_if<has_readDataFromFile<FileReaderPolicy>::value>::type* = nullptr>
		class FileReader {
		public:
			// constructor
			FileReader(const std::string& file_path = std::string("./data.dat"))
				: file_path_(file_path) {}

			FileReader(std::string&& file_path) : file_path_(std::move(file_path)) {}

			~FileReader() = default;

			auto readDataFromFile() {
				return std::move(readDataFromFile(this->file_path_));
			}

			auto readDataFromFile(const std::string& file_path) {
				return std::move(FileReaderPolicy::readDataFromFile(file_path));
			}   

		private:
			// 読み込み対象となるファイルのパス
			std::string file_path_;
		};
	}
}

#endif // _FILE_READER_

