#include <iostream>
#include <list>
#include <vector>
using namespace std;

int main() {
    vector<int> vec(3, 0);
    list<int> lst{1, 2, 3};
    
    copy(lst.begin(), lst.end(), vec.begin());
    for (const auto& num: vec) {
        cout << num << " ";
    }
    return 0;
}