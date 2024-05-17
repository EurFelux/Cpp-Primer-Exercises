#include <iostream>
#include <iterator>
#include <vector>
#include <deque>
using namespace std;

int main() {
    vector<int> vec1{1,2,3};
    deque<int> dq{4,5,6};
    vector<int> vec2{7,8,9};
    
    auto bi = back_inserter(vec1);
    auto fi = front_inserter(dq);
    auto ii = inserter(vec2, vec2.begin()+1);

    auto print = [&](){
        for (const auto& num: vec1)
            cout << num << " ";
        cout << endl;

        for (const auto& num: dq)
            cout << num << " ";
        cout << endl;
            
        for (const auto& num: vec2)
            cout << num << " ";
        cout << endl;
    };

    bi = 4;
    bi = 5;
    fi = 7;
    fi = 8;
    ii = 10;
    ii = 12;

    print();

    return 0;
}