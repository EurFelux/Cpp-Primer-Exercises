#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    vector<int> vec{1,2,3};
    cout << accumulate(vec.begin(), vec.end(), 0);
    return 0;
}