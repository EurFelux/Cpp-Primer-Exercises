#include <iostream>

using namespace std;

class HasPtr {
public:
    HasPtr(const std::string &s = std::string()): ps(new std::string(s)), i(0) {}
    HasPtr(const HasPtr& other): ps(new std::string(*(other.ps))), i(other.i) {}
private:
    std::string *ps;
    int i;
};