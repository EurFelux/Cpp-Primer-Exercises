#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int num{0};
    vector<int> vec;
    while (cin >> num) {
        vec.emplace_back(num);
    }
    cout << count(vec.begin(), vec.end(), 3);
    return 0;
}