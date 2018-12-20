#include <iostream>
#include <string>
#include <vector>
#include "FileWriter.h"

#include <typeinfo>

namespace t1 {
	using namespace tks::io;
	using namespace std;

	void test(const char* path) {
		const string fpath(path);
	
		FileWriter<> writer(fpath);
		vector<string> vec { string("hoge"), string("fugafaug") };

		writer.writeDataToFile(vec);
	}

	/*	
	void test(const char*) {
		vector<string> vec {"abc", "defgh", "ijklmn"};
		cout << boolalpha;
		cout << typeid(decltype(vec)).name() << endl;
		cout << "is_indexable : " << is_indexable<decltype(vec)>::value << endl; 
		cout << "has_size : " << has_size<decltype(vec)>::value << endl; 
	}
	*/
}


auto main(int argc, char* argv[]) -> int {
	if(argc < 2)
		std::cout << "Too few command line argument." << std::endl, std::exit(EXIT_FAILURE);
	t1::test(argv[1]);
}

