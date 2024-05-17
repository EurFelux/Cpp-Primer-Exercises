#include <iostream>
#include <fstream>
#include <vector>
#include <string>


using std::ifstream, std::ofstream;
using std::cout, std::endl;
using std::string;
using std::vector;

vector<string> read_and_write(string file_path) {
    ifstream ifs(file_path, ifstream::in);
    vector<string> lines;
    string line;
    while (getline(ifs, line)) {
        lines.push_back(line);
    }
    ifs.close();
    return lines;
}


int main(int argc, char const *argv[])
{
    vector<string> lines = read_and_write("./8.4.cpp");
    for (auto line : lines) {
        cout << line << endl;
    }
    return 0;
}
