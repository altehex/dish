#include <iostream>
#include <string>



std::string help_msg = 
    "cd <arg ...>"
    "echo <arg ...>";



void help() 
{
    std::cout << help_msg;
}
