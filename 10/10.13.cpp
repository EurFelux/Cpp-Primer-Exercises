#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <typename T>
void print(const vector<T>& vec) {
    for (const auto& item : vec)
        cout << item << " ";
    cout << endl;
}

int main() {
    vector<string> vec{"abcd", "asdawd", "adsadawdasdzxf", "asd"};
    auto moreThanFive = [](const string& str){return str.length() > 5u;};
    auto last = partition(vec.begin(), vec.end(), moreThanFive);
    for (auto it = vec.cbegin(); it != last; ++it)
        cout << *it << " ";
    cout << endl;
    return 0;
}