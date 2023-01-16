#pragma once



#include <string>
#include <unordered_map>
#include <vector>


using namespace std;



#include "echo.hpp"
#include "exit.hpp"



using builtin = int (*)(vector<string>);

unordered_map<string, builtin> 
builtins = {
    //{"cd",          &cd     },
    //{"clear",       &clear  },
    //{"dishwasher",  &clear  },
    {"echo",        &echo   },
    //{"help",        &help   }
    {"exit",        &exit   },
    {"quit",        &exit   },
    {"undefined",   nullptr }
};
