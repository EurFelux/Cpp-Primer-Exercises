/**
 * 没什么区别，就改一下类型，api都能用。
*/

#include <iostream>
#include <sstream>
#include <string>
#include <list>

using namespace std;

int main(int argc, char const *argv[])
{
    list<string> lst;
    string str;
    while (cin >> str) {
        lst.push_back(str);
    }

    for (auto it = lst.cbegin(); it != lst.cend(); ++it) {
        cout << *it << " ";
    }
    
    return 0;
}
