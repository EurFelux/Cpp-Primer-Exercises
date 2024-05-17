#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {

    ifstream in("test.txt");
    vector<string> data;

    if (!in.is_open()) {
        cout << "File cannot be opened." << endl;
        return 1;
    }

    // create map
    map<string, set<int>> row_map;
    map<string, int> word_count;
    string s;
    for(int i = 0; getline(in, s); ++i) { // for each line
        istringstream iss(s);
        string word;
        while (iss >> word) {
            // update row_map
            row_map[word].insert(i);
            // update word_count
            ++word_count[word];
        }
        data.push_back(s);
    }

    // interaction
    while (true) {
        // prompt
        cout << "query a word: ";
        string word;
        cin >> word;

        // query
        if (row_map.find(word) != row_map.end()) {
            cout << endl;
            cout << word << " occurs " << word_count[word] << " times:" << endl;
            auto row_set = row_map[word];
            for (const auto& item : row_set) {
                cout << "\t(line " << item << ") " << data[item] << endl;
            }
        }
    }
    return 0;
}