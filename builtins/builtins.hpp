#pragma once



#include <functional>
#include <string>
#include <unordered_map>
#include <vector>


using namespace std;



int cd(vector<string> args);
// alias "dishwasher"
int clear();
int echo(string line);
int help();



const unordered_map<string, function<vector<string>>(string)> builtins = 
{
    {"cd", &cd},
    {"dishwasher", &clear},
    {"clear", &clear}
};
