#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ifstream policy_in("policy.txt");
    ifstream to_convert_in("to_convert.txt");

    // get policy
    map<string, string> policy_map;
    string line;
    while (getline(policy_in, line)) {
        istringstream line_in(line);
        string key_word;
        string mapped_part;
        line_in >> key_word;
        std::getline(line_in, mapped_part);
        cout << "key: " << key_word << " " << "mapped_part: " << mapped_part << endl;
        policy_map[key_word] = mapped_part.substr(1); // 去除前导空格
    }
    policy_in.close();

    // get to_convert
    vector<string> to_convert;
    while (getline(to_convert_in, line)) {
        to_convert.push_back(line);
    }
    to_convert_in.close();

    // replace
    for (auto& to_line : to_convert) {
        istringstream stream(to_line);
        ostringstream out;
        string word;
        while (stream >> word) {
            if (policy_map.find(word) == policy_map.end())
                out << word;
            else
                out << policy_map[word];
            out << " ";
        }
        to_line = out.str();
    }

    // print
    for (const auto& line : to_convert) {
        cout << line << endl;
    }

    return 0;
}