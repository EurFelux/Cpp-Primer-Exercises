#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print(const vector<int>& vec) {
    for (const auto& num : vec)
        cout << num << " ";
    cout << endl;
}

void elimDups(vector<int>& vec) {
    sort(vec.begin(), vec.end());
    auto last = unique(vec.begin(), vec.end());
    print(vec);
    vec.erase(last, vec.end());
    print(vec);
}

int main() {

    vector<int> vec{1,5,3,2,1,5,2,6,3,1,3};
    
    print(vec);

    elimDups(vec);
    
    return 0;
}