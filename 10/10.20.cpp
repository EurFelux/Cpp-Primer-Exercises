#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // use count_if to count how many words, whose length is more than 6, we have.
    vector<string> vec{"123", "123456", "1234567", "asdasdasd"};
    cout << count_if(vec.cbegin(), vec.cend(), [](const string& s){
        return s.length() > 6;
    });
    return 0;
}