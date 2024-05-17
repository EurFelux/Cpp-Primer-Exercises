#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

int main() {
    vector<int> vec{1,4,2,5,6,3};
    ostream_iterator<int> out(cout, " ");
    copy(vec.rbegin(), vec.rend(), out);
    cout << endl;
    return 0;
}