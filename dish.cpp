#include <iostream>
#include <string>

#include "lib.hpp"
#include "parser.hpp"



using namespace std;



const ryml::csubstr prompt = config["prompt"].val();



int input();



int main() 
{
    cout << config["welcome"].val() << '\n';
    
    do {} while (!input());

    return EXIT_SUCCESS;
}



int input() 
{
    cout << prompt;

    string command;
    getline(std::cin >> std::ws, command, '\n');

    return exec(split(command));;
}
