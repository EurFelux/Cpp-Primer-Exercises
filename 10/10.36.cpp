#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int main() {
    list<int> lst{1,3,2,5,6,7,0};
    auto it = find(lst.crbegin(), lst.crend(), 0);
    cout << *it;
    return 0;
}