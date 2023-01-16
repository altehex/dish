#include <iostream>
#include <string>
#include <vector>


using namespace std;



int echo(vector<string> line) 
{   
    for (int x = 1; x < line.size(); x++) {
        cout << line[x] << ' ';
    }
    cout << '\n';
    return EXIT_SUCCESS;
}
