#include <cstdlib>
#include "lib.h"



#define EXIT_SUCCESS    0

const string prompt = get_prompt();



void main_loop();
int input(char * line, char ** args);



int main(int argc, char **argv) {

    main_loop();

    return EXIT_SUCCESS;

}



void main_loop() {

    char *line;     // 
    char **args;    // 
    int status;

    do {

        status = input(line, args);

    } while (status);

}



int input(char * line, char ** args) {

    printf("%s", prompt.c_str());

    

    return 1;

}


// Use Result type!!!
