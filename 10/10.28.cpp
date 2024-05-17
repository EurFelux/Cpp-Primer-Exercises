#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <deque>
using namespace std;

int main() {
    vector<int> vec{1,2,3,4,5,6,7,8,9};
    vector<int> vec2;
    vector<int> vec3;
    deque<int> dq;

    copy(vec.begin(), vec.end(), back_inserter(vec2));
    copy(vec.begin(), vec.end(), front_inserter(dq));
    copy(vec.begin(), vec.end(), inserter(vec3, vec3.begin()));
    
    for(auto& num: vec2) {
        cout << num << " ";
    }
    cout << endl;

    for(auto& num: dq) {
        cout << num << " ";
    }
    cout << endl;

    for(auto& num: vec3) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}