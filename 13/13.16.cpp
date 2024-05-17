#include <iostream>

using namespace std;

class numbered {
public:
    numbered();
    numbered(const numbered&);
    unsigned mysn;
private:
    static unsigned next_number;
};

numbered::numbered() : mysn(numbered::next_number++) {}

numbered::numbered(const numbered& x): mysn(numbered::next_number++) {}

unsigned numbered::next_number = 0;

void f (const numbered& s) {
    cout << s.mysn << endl;
}

int main() {
    numbered a, b = a, c = b;
    f(a);
    f(b);
    f(c);
    return 0;
}