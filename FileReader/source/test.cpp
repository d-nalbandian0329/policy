#include <iostream>
#include <string>
#include "../header/FileReader.h"

namespace t1 {
	using namespace tks::io;
	using namespace std;

	void test(const char* path) {
		const string file_path(path);
		
		FileReader<> reader(file_path); 

		auto data_set = reader.readDataFromFile();
		for(const auto& str : data_set)
			cout << str << endl;
	}
}


auto main(int argc, char* argv[]) -> int {
	t1::test(argv[1]);
}

