#pragma once



#include <functional>
#include <string>
#include <unordered_map>
#include <vector>


using namespace std;



int cd(vector<string> args);
// alias "dishwasher"
int clear(vector<string> args);
int echo(vector<string> args);
int help(vector<string> args);



using builtin = int (*)(vector<string>);

unordered_map<string, builtin> 
builtins = {
    {"cd",          &cd     },
    {"clear",       &clear  },
    {"dishwasher",  &clear  },
    {"echo",        &echo   },
    {"help",        &help   }
};
