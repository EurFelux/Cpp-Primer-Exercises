#include <iostream>
#include <string>
#include <memory>

using namespace std;

int main() {
    constexpr int n = 5;
    // string *const p = new string[n];
    allocator<string> alloc;
    auto const p = alloc.allocate(n);
    auto q = p;
    string s;
    while (cin >> s && q != p + n) {
        construct_at(q, s);
        ++q;
    }
    const size_t size = q - p;

    for (q = p; q != p + size; ++q)
        cout << *q << endl;
    
    for (q = p; q != p + size; ++q)
        destroy_at(q);

    alloc.deallocate(p, n);
    return 0;
}