#pragma once

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif


#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#include "ryml.hpp"



using namespace std;



vector<string> split(string command) {

    command.append(" END");
	
	vector<string> tokens = {};
	string token = strtok(&*( command.begin() ), " ");

	while (token != "END") {

		tokens.emplace_back(token);
		token = strtok(nullptr, " ");

	}

	return tokens;

}



template<class container>
container file_get_contents(const char * filename);

// YAML parser(rapidyaml)
ryml::Tree parse_file(const char * filename) {

	string contents = file_get_contents<string>(filename);
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
