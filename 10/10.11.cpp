#include <iostream>
#include <vector>
#include <algorithm>

using std::vector, std::cout, std::endl;

void print(const vector<int>& vec) {
    for (const auto& num : vec)
        cout << num << " ";
    cout << endl;
}

bool less(const int& a, const int& b) {
    return a < b;
}

void elimDups(vector<int>& vec) {
    stable_sort(vec.begin(), vec.end(), less);
    auto last = unique(vec.begin(), vec.end());
    print(vec);
    vec.erase(last, vec.end());
    print(vec);
}

int main() {
    vector<int> vec{1,5,2,5,2,65,2,5,12,4,1,2,5,3,65,2,6};
    elimDups(vec);
    return 0;
}