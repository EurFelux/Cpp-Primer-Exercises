#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <array>

using std::string;
using std::istringstream, std::ostringstream;
using std::cout, std::endl;
using std::vector;
using std::array;

int main() {
    string line = "See me.";
    istringstream in(line);
    ostringstream out;
    string word;
    while (in >> word) {
        out << word << " ";
    }

    cout << out.str() << endl;

    return 0;
}