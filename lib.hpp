#pragma once
#define RYML_SINGLE_HDR_DEFINE_NOW



#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

#include "builtins/builtins.hpp"
#include "parser.hpp"
#include "ryml.hpp"


using namespace std;



ryml::Tree no_dish_yml ();



// |+--+--+--+--+--+--+--+--+--+--+--+--
// |
// |        STRUCTURES
// |
// |+--+--+--+--+--+--+--+--+--+--+--+--

//
// dish.yml
//----------------------
const ryml::Tree config = (fopen("dish.yml", "rb") == nullptr) ? 
    no_dish_yml() : 
    parse_file("dish.yml");


// |+--+--+--+--+--+--+--+--+--+--+--+--
// |
// |        STRUCTURES
// |
// |+--+--+--+--+--+--+--+--+--+--+--+--

ryml::Tree no_dish_yml () 
{
    SetConsoleOutputCP(CP_UTF8);

    cout << "[ ! ] Can't find 'dish.yml'.\n" <<
            "[ • ] Using the 'dish/default.yml' file.\n";

    return parse_file("dish/default.yml");
}


int exec(vector<string> command) 
{
    // calling some other program
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    if ( CreateProcessA(
        NULL,
        &*(command[0].begin()),
        NULL,
        NULL,
        true,
        0,
        NULL,
        NULL,
        &si,
        &pi ) 
    ) {
    
        WaitForSingleObject(
            pi.hProcess,
            INFINITE
        );

        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);

        return EXIT_SUCCESS;

    }


    // calling builtins
    if (builtins.find(command[0]) != builtins.end()) 
    {
        return builtins[command[0].c_str()](command);
    }


    cout << "[ ! ] No such command: " << command[0] <<"\n";
        
    return EXIT_SUCCESS;
}
