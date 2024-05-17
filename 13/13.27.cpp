#include <iostream>
#include <algorithm>
#include <type_traits>

using std::cout;
using std::endl;
using std::string;


// 行为类指针
class HasPtr {
public:
    friend void swap(HasPtr&, HasPtr&);
    HasPtr() : i(0), p(new string), ref_count(new int{1}) {
        cout << "default constructor" << endl;
    };
    HasPtr(const string& str) : i(0), p(new string(str)), ref_count(new int{1}) {
        cout << "constructor with str" << endl;
    };
    HasPtr(const HasPtr&);
    HasPtr& operator=(const HasPtr&);
    ~HasPtr();

private:
    int* ref_count;
    int i;
    string* p;
};

HasPtr::HasPtr(const HasPtr& rhs) : i(rhs.i), p(rhs.p), ref_count(rhs.ref_count){
    cout << "copy constructor" << endl;
    *ref_count += 1;
}

HasPtr& HasPtr::operator=(const HasPtr& rhs) {
    cout << "copy assignment operator" << endl;
    *(rhs.ref_count) += 1; // 看起来是修改了rhs.ref_count，但实际上是修改了*(rhs.ref_count)，所以对 const HasPtr& 而言仍然是合法的
    if (*ref_count == 1) {
        delete p;
        delete ref_count;
    }
    ref_count = rhs.ref_count;
    p = rhs.p;
    return *this;
}

HasPtr::~HasPtr() {
    if (*ref_count == 1) {
        --ref_count;
        delete ref_count;
        delete p;
    }
}

void swap(HasPtr& lhs, HasPtr& rhs) {
    std::swap(lhs.p, rhs.p);
    std::swap(lhs.i, rhs.i);
    std::swap(lhs.ref_count, rhs.ref_count);
}

class Foo {
public:
    friend void swap_1(Foo&, Foo&);
    friend void swap_2(Foo&, Foo&);
    Foo(HasPtr p) : h(p) {}
private:
    HasPtr h;
};

void swap_1(Foo& lhs, Foo& rhs) {
    std::swap(lhs.h, rhs.h);
}

void swap_2(Foo& lhs, Foo& rhs) {
    using std::swap;
    swap(lhs.h, rhs.h);
}

int main() {
    HasPtr p1("haha");
    Foo f1(p1);
    HasPtr p2("hooh");
    Foo f2(p2);
    // cout << std::is_move_constructible<HasPtr>::value << endl;
    // cout << std::is_move_assignable<HasPtr>::value << endl;
    cout << "std::swap: " << endl;
    swap_1(f1, f2);
    cout << "swap:" << endl;
    swap_2(f1, f2);
    return 0;
}