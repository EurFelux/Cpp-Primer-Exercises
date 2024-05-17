#include <iostream>
using namespace std;

int main() {
    int v{5};
    auto lambda = [v]()mutable{
        --v;
        cout << "v: " << v << endl;
        return v == 0;
    };
    while (!lambda());
    return 0;
}