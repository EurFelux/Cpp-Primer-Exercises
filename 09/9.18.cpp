#include <iostream>
#include <sstream>
#include <string>
#include <deque>

using namespace std;

int main(int argc, char const *argv[])
{
    deque<string> q;
    string str;
    while (cin >> str) {
        q.push_back(str);
    }

    for (auto it = q.cbegin(); it != q.cend(); ++it) {
        cout << *it << " ";
    }
    
    return 0;
}
