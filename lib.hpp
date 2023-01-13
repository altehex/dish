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
    cout << "[ ! ] Can't find 'dish.yml'.\n" <<
            "[ • ] Using the 'dish/default.yml' file.\n";
    return parse_file("dish/default.yml");
}


int exec(vector<string> command) 
{
    // calling builtins
    if (builtins.find(command[0]) != builtins.end()) 
    {
        string key = command[0];
        builtins[key.c_str()](command);
        return EXIT_SUCCESS;
    }


    // calling some other program
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    if ( !CreateProcessA(
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
        cout << "[ ! ] Failed to start a process\n" <<
                "[ ! ] Error code: " << GetLastError() << '\n';
    } else {
        WaitForSingleObject(
            pi.hProcess,
            INFINITE
        );

        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
        
    }

    return EXIT_SUCCESS;
}
