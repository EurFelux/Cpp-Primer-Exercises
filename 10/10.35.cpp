#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

int main() {
    vector<int> vec{1,4,2,5,6,3};
    for (auto it = vec.end()-1; it != vec.begin(); --it) {
        cout << *it << " ";
    }
    cout << *vec.begin() << endl;

    return 0;
}