#ifndef _FILE_WRITER_
#define _FILE_WRITER_

#include <iostream>
#include <fstream>
#include <utility>
#include <type_traits>

#include "AsciiFileWriterPolicy.h"

namespace tks {
	namespace io {
		struct is_indexable_impl {
			template <class T>
			static auto check(T*) -> decltype(std::declval<T>().operator[](0), std::true_type());

			template <class T>
			static auto check(...) -> std::false_type;
		};

		template <class T>
		class is_indexable : public decltype(is_indexable_impl::check<T>(nullptr)) {};



		struct has_size_impl {
			template <class T>
			static auto check(T*) -> decltype(std::declval<T>().size(), std::true_type());

			template <class T>
			static auto check(...)->std::false_type;
		};

		template <class T>
		class has_size : public decltype(has_size_impl::check<T>(nullptr)) {};


		template <class FileWriterPolicy = AsciiFileWriterPolicy>
		class FileWriter {
		public:
			FileWriter(const std::string& file_path = std::string("./data.dat"))
				: file_path_(file_path) {}

			FileWriter(std::string&& file_path) : file_path_(std::move(file_path)) {}

			~FileWriter() = default;

			template <class IndexableContainer>
			bool writeDataToFile(IndexableContainer&& container) {
				return this->writeDataToFile(this->file_path_, std::forward<IndexableContainer>(container));
			}

			template <class IndexableContainer /*,
						typename std::enable_if<
							is_indexable<IndexableContainer>::value
							&&
							has_size<IndexableContainer>::value>::type* = nullptr*/>
			bool writeDataToFile(const std::string& file_path, IndexableContainer&& container) {
				return FileWriterPolicy::writeDataToFile(file_path, std::forward<IndexableContainer>(container));
			}


			/*
			// size() 持ってない方
			template <class IndexableContainer>
			bool writeDataToFile(IndexableContainer&& container, std::size_t total_size) {
				return this->writeDataToFile(this->file_path_, std::forward<IndexableContainer>(container), total_size);
			}

			template <class IndexableContainer,
					 	typename std::enable_if<
							is_indexable<IndexableContainer>::value
							&&
							!has_size<IndexableContainer>::value>::type* = nullptr>
			bool writeDataToFile(const std::string& file_path, IndexableContainer&& container, std::size_t total_size) {
				return FileWriterPolicy::writeDataToFile(file_path, std::forward<IndexableContainer>(container), total_size);
			}
			*/

		private:
			std::string file_path_;
		};
	}
}

#endif // _FILE_WRITER_
