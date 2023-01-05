#pragma once
#define RYML_SINGLE_HDR_DEFINE_NOW

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


ryml::Tree config = parse_file("dish.yml");



// |+--+--+--+--+--+--+--+--+--+--+--+--
// |
// |        FUNCTIONS
// |
// |+--+--+--+--+--+--+--+--+--+--+--+--



string get_prompt() {

    return config["prompt"].val().str;

}
