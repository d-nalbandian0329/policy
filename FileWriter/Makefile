gpp_options = -std=c++14 -Wall --pedantic-error
include_dir = ./header/
source_dir  = ./source/
obj_dir     = ./obj/

command_arg = ./data.txt


a.out : main.o AsciiFileWriterPolicy.o
	g++ $(gpp_options) -I$(include_dir) -o $@ $(obj_dir)main.o $(obj_dir)AsciiFileWriterPolicy.o


main.o : $(source_dir)main.cpp $(include_dir)FileWriter.h $(include_dir)AsciiFileWriterPolicy.h
	g++ $(gpp_options) -I$(include_dir) -c -o $(obj_dir)$@ $<  #$(obj_dir)AsciiFileWriterPolicy.o


AsciiFileWriterPolicy.o : $(source_dir)AsciiFileWriterPolicy.cpp $(include_dir)AsciiFileWriterPolicy.h
	g++ $(gpp_options) -I$(include_dir) -c -o $(obj_dir)$@ $<


BinaryFileWriterPolicy.o : $(source_dir)BinaryFileWriterPolicy.cpp $(include_dir)BinaryFileWriterPolicy.h	
	g++ $(gpp_options) -I$(include_dir) -c -o $(obj_dir)$@ $<


run :
	./a.out $(command_arg)

.PHONY : run

