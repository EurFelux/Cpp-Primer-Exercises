#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <iterator>
using namespace std;

int main() {
    vector<int> vec{1,2,3,1,3,2,45,2,4,1,24,24,13,1,21,213,4};
    list<int> lst;
    sort(vec.begin(), vec.end());
    // 只会将不重复元素copy过去，逻辑尾迭代器以后的部分被无视
    unique_copy(vec.begin(), vec.end(), back_inserter(lst));
    
    for (const auto& num: lst) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}