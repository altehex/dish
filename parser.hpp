#pragma once


#include <cstdio>
#include <iostream>
#include <string>
#include "ryml.hpp"


using namespace std;



template<class container>
container file_get_contents(const char * filename);



ryml::Tree parse_file(const char * filename) {

	string contents = file_get_contents<string>(filename);
	cout << contents;
	return ryml::parse_in_arena(ryml::to_csubstr(contents));

}



template<class container>
container file_get_contents(const char * filename) {
	
	container buffer;
	FILE * fp = fopen(filename, "rb");

	fseek(fp, 0, SEEK_END);

	long sz = ftell(fp);
	buffer.resize(static_cast<typename container::size_type>(sz)); 

	if (sz) {

		rewind(fp);
		size_t ret = fread(&buffer[0], 1, buffer.size(), fp);

	}

	fclose(fp);
	return buffer;

}
