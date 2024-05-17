#include <iostream>

using namespace std;

class X {
public:
    X();
    X(const X&); // copy constructor
    ~X(); // desctructor
    X& operator=(const X&); // copy-assignment operator
private:
    int foo;
};

X::X(): foo(0) {
    cout << "default constructor" << endl;
}

X::X(const X& x) {
    foo = x.foo;
    cout << "copy constructor" << endl;
}

X::~X() {
    cout << "destructor" << endl;
}

X& X::operator=(const X& rhs) {
    cout << "copy-assignment operator" << endl;
    return *this;
}

int main() {
    X x1, x2(x1), x3 = x1;
    x3 = x2;
    return 0;
}