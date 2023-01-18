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

    string command = get_line();

    return exec(split(command));;
}


string get_line() 
{
    string line;
    string processedLine;

    while (processedLine.back() != '\n') 
    {
        getline(std::cin >> std::ws, line, '\n');
        processedLine += line;

        if (line.back() == '>' || line.back() == '\\') 
        {
            cout << "<";
            processedLine.pop_back();
            processedLine += ' ';

        } else processedLine += '\n';
    }

    processedLine.pop_back();

    return processedLine;
}
