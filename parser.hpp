#pragma once


#include <cstdio>
#include <string>
#include "ryml.hpp"


using namespace std;



template<class container>
size_t file_get_contents(
	const char * filename,
	container * buffer
);

/*
template<class container>
void file_put_contents(
	const char* filename,
	container const& buffer,
	const char* acces
);
*/

ryml::Tree parse_file(const char * filename) {

	string contents;
	//if (file_get_contents<string>(filename, &contents) == -1) {
	//	return NULL;
	//};
	file_get_contents<string>(filename, &contents);
	return ryml::parse_in_arena(ryml::to_csubstr(contents));

}



// Читает файл и сохраняет содержимое в буфер
template<class container>
size_t file_get_contents(
	const char * filename,
	container * buffer
) {
	
	FILE * fp = fopen(filename, "rb");
	if (fp == NULL) {
		perror("achtung");
	}

	fseek(fp, 0, SEEK_END);

	long sz = ftell(fp);
		//задаём размер для буфера
	buffer->resize(static_cast<typename container::size_type>(sz)); 

	if (sz) {

		rewind(fp);
		size_t ret = fread(&(*buffer), 1, buffer->size(), fp);

	}

	fclose(fp);
	return buffer->size();

}

/*
// Записывает содержимое буфера в файл
template<class container>
void file_put_contents(
	string filename,
	container const & buffer,
	const char * access
) {

	FILE* fp = fopen(filename.c_str, access);

	const char * buffer_1 = buffer.empty() ? "" : &buffer[0];
	fwrite(buffer_1, 1, buffer.size(), fp);
	fclose(fp);

}
*/
