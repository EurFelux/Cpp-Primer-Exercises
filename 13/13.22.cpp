/*
需求不明确真的很蛋疼。
*/

#include <iostream>

using namespace std;

class HasPtr {
public:
    HasPtr(int _i = 0, string* _p = nullptr) : i(_i), p(_p){}
    HasPtr(int _i = 0, const string& s = "") : i(_i), p(new string(s)) {}
    ~HasPtr();
    HasPtr(const HasPtr&);
    HasPtr& operator=(const HasPtr&);
private:
    int i;
    // 必须是动态分配的内存，否则UB
    string* p;
};

HasPtr::~HasPtr() {
    if (p)
        delete p;
}

HasPtr::HasPtr(const HasPtr& x) : i(x.i) {
    if (x.p)
        p = new string(*(x.p));
    else
        p = nullptr;
}

HasPtr& HasPtr::operator=(const HasPtr& rhs) {
    i = rhs.i;
    if (rhs.p) {
        *p = *(rhs.p);
    } else {
        delete p;
        p = nullptr;
    }
    
    return *this;
}

int main() {
    
    return 0;
}