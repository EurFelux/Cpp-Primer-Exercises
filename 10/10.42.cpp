#include <iostream>
#include <list>
#include <iterator>

using namespace std;

int main() {
    list<int> lst{1,5,2,5,2,6,32,2,4,2,1,4};
    lst.sort();
    lst.unique();
    
    ostream_iterator<int> out(cout, " ");
    copy(lst.begin(), lst.end(), out);
    return 0;
}