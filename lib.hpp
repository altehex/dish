#pragma once
#define RYML_SINGLE_HDR_DEFINE_NOW

#include <iostream>
#include "parser.hpp"
#include <string>
#include "ryml.hpp"


using namespace std;



// |+--+--+--+--+--+--+--+--+--+--+--+--
// |
// |        STRUCTURES
// |
// |+--+--+--+--+--+--+--+--+--+--+--+--

struct Result {
    void* result;
    int error;
};


const ryml::Tree config = parse_file("dish.yml");



// |+--+--+--+--+--+--+--+--+--+--+--+--
// |
// |        FUNCTIONS
// |
// |+--+--+--+--+--+--+--+--+--+--+--+--



ryml::csubstr get_prompt() {

    ryml::csubstr prompt = config["prompt"].val();
    return prompt;

}

