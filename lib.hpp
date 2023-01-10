#pragma once
#define RYML_SINGLE_HDR_DEFINE_NOW



#include <cstdio>
#include <iostream>
#include <string>

#include "parser.hpp"
#include "ryml.hpp"


using namespace std;



// |+--+--+--+--+--+--+--+--+--+--+--+--
// |
// |        STRUCTURES
// |
// |+--+--+--+--+--+--+--+--+--+--+--+--

ryml::Tree no_dish_yml () 
{
    cout << "Can't find 'dish.yml'.\n" <<
    "Using the 'dish/default.yml' file.\n";
    return parse_file("dish/default.yml");
}

//
// dish.yml
//----------------------
const ryml::Tree config = (fopen("dish.yml", "rb") == nullptr) ? 
    no_dish_yml() : 
    parse_file("dish.yml");



void fork(string command) 
{
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

//    if (command == "quit" || 
  //      command == "exit") return -1;

    if ( !CreateProcessA(
        NULL,
        &*(command.begin()),
        NULL,
        NULL,
        false,
        0,
        NULL,
        NULL,
        &si,
        &pi ) 
    ) {
        cout << "Failed to start a process\n" <<
                "Error code: " << GetLastError() << '\n';
    } else {
        WaitForSingleObject(
            pi.hProcess,
            INFINITE
        );

        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
    }
}
