#include <iostream>
#include <set>

using namespace std;

int main() {

    auto comp = [](const int& left, const int& right){
        return left < right;
    };

    using tp = bool(*)(const int& left, const int& right);

    multiset<int, bool(*)(const int& left, const int& right)> m(comp); 

    
    return 0;
}