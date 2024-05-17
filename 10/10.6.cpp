#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> vec{1,2,3};
    fill_n(vec.begin(), vec.size(), 0);
    for (const auto& num : vec) {
        cout << num << " ";
    }

    return 0;
}