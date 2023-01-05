#define _CRT_SECURE_NO_WARNINGS



#include <iostream>
#include <string>

#include "lib.hpp"



const string prompt = get_prompt();



void main_loop();
int input(char* line, char** args);



int main(int argc, char** argv) {

    main_loop();

    return EXIT_SUCCESS;

}



void main_loop() {

    char* line = nullptr;     // 
    char** args = nullptr;    // 
    int status;

    do {

        status = input(line, args);

    } while (status);

}



int input(char* line, char** args) {

    cout << prompt;

    return 1;

}


// Use Result type!!!
