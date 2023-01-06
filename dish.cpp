#define _CRT_SECURE_NO_WARNINGS



#include <iostream>
#include <string>

#include "lib.hpp"



using namespace std;



ryml::csubstr prompt = get_prompt();



int input(char* line, char** args);



int main(int argc, char** argv) {

    cout << config["welcome"].val();

    char* line = nullptr;     // 
    char** args = nullptr;    // 
    int status;

    do {

        status = input(line, args);

    } while (status);

    return 0;

}



int input(char* line, char** args) {

    cout << prompt;

    return 0;

}


// Use Result type!!!
