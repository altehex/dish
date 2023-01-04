#include <filesystem>
#include <string>

using namespace std;



///
/// Structures
///------------------------------

template<class T>
struct Result {
    T result;
    int error;
};



///
/// Functions
///---------------------------------




string get_prompt() {

    string prompt = ">";
    return prompt;

}
