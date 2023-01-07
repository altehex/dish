#pragma once
#define RYML_SINGLE_HDR_DEFINE_NOW



#include <cstdio>
#include <iostream>
#include <string>

#include "define.hpp"
#include "parser.hpp"
#include "ryml.hpp"


using namespace std;



// |+--+--+--+--+--+--+--+--+--+--+--+--
// |
// |        STRUCTURES
// |
// |+--+--+--+--+--+--+--+--+--+--+--+--

template<class T>
union result {
    T result;
    int error;
};


//
// dish.yml
//----------------------
const ryml::Tree config = (fopen("dish.yml", "rb") == nullptr) ? 
    parse_file("dish/default.yml") : 
    parse_file("dish.yml");


