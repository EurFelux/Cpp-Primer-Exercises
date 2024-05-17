#include <iostream>
#include <string>
#include <functional>
#include <algorithm>

using namespace std;
using namespace std::placeholders;

bool check_size(const string& s, const int& size) {
    return s.size() > size;
}

int main() {
    vector<string> vec{"asdav", "asdfasd", "asd", "asfasdas"};
    cout << count_if(vec.begin(), vec.end(), bind(check_size, _1, 6));
    return 0;
}