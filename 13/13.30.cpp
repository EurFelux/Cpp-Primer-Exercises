/*
需求不明确真的很蛋疼。
*/

#include <iostream>
#include <vector>
#include <algorithm>

// using namespace std;

using std::vector;
using std::string;
using std::cout;
using std::endl;

// 行为类值
class HasPtr {
public:
    friend void swap(HasPtr&, HasPtr&);
    HasPtr() : i(0), p(new string("")) {}
    HasPtr(const string& s) : i(0), p(new string(s)) {}
    HasPtr(const char* s) : i(0), p(new string(s)) {}
    HasPtr(const HasPtr&);
    HasPtr& operator=(const HasPtr&);
    ~HasPtr();
    bool operator<(const HasPtr&);
    void print() const {
        cout << *p << " ";
    }
private:
    int i;
    string* p;
};

HasPtr::~HasPtr() {
    delete p;
}

HasPtr::HasPtr(const HasPtr& x) : i(x.i), p(new string(*(x.p))) {}

HasPtr& HasPtr::operator=(const HasPtr& rhs) {
    i = rhs.i;
    delete p;
    p = new string(*(rhs.p));
    
    return *this;
}

void swap(HasPtr& lhs, HasPtr& rhs) {
    using std::swap;
    swap(lhs.i, rhs.i);
    swap(lhs.p, rhs.p);
    cout << "swap" << endl;
}

bool HasPtr::operator<(const HasPtr& rhs) {
    // by string
    return *p < *(rhs.p);
}

int main() {
    vector<HasPtr> vec{"abc", "dsa", "asdw", "abcd", "bsd"};
    using std::sort;
    // 答案是一次swap都不会调用，因为gcc实现对于元素量小于16的容器使用插入排序，而插入排序的实现未使用swap函数
    sort(vec.begin(), vec.end());
    for (const auto& item : vec) {
        item.print();
    }
    return 0;
}