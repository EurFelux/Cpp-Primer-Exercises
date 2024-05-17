#include <iostream>
#include <string>
#include <vector>
#include <functional>

using namespace std;
using namespace std::placeholders;

bool check_size(const string& s, const string::size_type& i) {
    return s.size() < i;
}

int main() {
    vector<int> vec{1,2,4,512,5,12,51,25,15,123};
    string str{"1231"};
    auto it = find_if(vec.cbegin(), vec.cend(), bind(check_size, str, _1));
    cout << *it;
    return 0;
}