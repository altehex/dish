


#include <iostream>
#include <string>

#include "define.hpp"
#include "lib.hpp"
#include "parser.hpp"



using namespace std;



const ryml::csubstr prompt = config["prompt"].val();



int input(char* line, char** args);



int main(int argc, char** argv) {

    cout << config["welcome"].val() << '\n';

    char* line = nullptr;     // 
    char** args = nullptr;    // 
    int status;

    do {

        status = input(line, args);

    } while (!status);

    return EXIT_SUCCESS;

}



int input(char* line, char** args) {

    cout << prompt;

    string command;
    getline(std::cin >> std::ws, command, '\n');

    vector<string> parsed = split(command);

    return EXIT_SUCCESS;

}


// Use Result type!!!
