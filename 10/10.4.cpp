#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main() {
    vector<double> vec{1.0, 2.0, 3.1};
    cout << accumulate(vec.cbegin(), vec.cend(), 0.);
    return 0;
}