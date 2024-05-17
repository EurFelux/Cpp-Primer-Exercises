#include <iostream>
#include <memory>

using namespace std;

int main() {
    unique_ptr<int> p(new int(42));

    // use of deleted function
    // unique_ptr<int> q(p);

    // use of deleted function
    unique_ptr<int> q;
    q = p;

    return 0;
}