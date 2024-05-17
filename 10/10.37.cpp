#include <iostream>
#include <vector>
#include <list>
#include <iterator>
using namespace std;

int main()
{
    vector<int> vec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    list<int> lst;
    // copy(vec.crbegin() + (vec.size() - 7 - 1), vec.crend() - 3, back_inserter(lst));
    copy(vec.crbegin() + (vec.size() - 7 - 1), vec.crbegin() + (vec.size() - 3), back_inserter(lst));
    // copy(vec.begin()+3, vec.begin()+7+1, front_inserter(lst));

    ostream_iterator<int> out(cout, " ");
    copy(lst.begin(), lst.end(), out);
    return 0;
}