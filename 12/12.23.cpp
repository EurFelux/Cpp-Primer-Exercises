#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main() {
    // version 1
    const char* cs1 = "asddaw";
    const char* cs2 = "ASDAS";
    char* dest = new char[strlen(cs1) + strlen(cs2) + 1];
    dest[0] = '\0';
    strcat(dest, cs1);
    strcat(dest, cs2);
    cout << dest << endl;

    // version 2
    string s1("asddsa");
    string s2("ASDDSA");
    char* dest2 = new char[s1.size() + s2.size() + 1];
    dest2[0] = '\0';
    strcat(dest2, (s1+s2).c_str());
    cout << dest2 << endl;
    return 0;
}