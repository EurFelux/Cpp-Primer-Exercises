#include <iostream>
#include <algorithm>
#include <list>
#include <string>

using namespace std;

int main() {
    string str;
    list<string> lst;
    while (cin >> str) {
        lst.emplace_back(str);
    }
    cout << count(lst.begin(), lst.end(), "123");
    return 0;
}