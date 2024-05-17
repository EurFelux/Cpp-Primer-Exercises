#include <iostream>

class Foo
{
public:
    Foo(){}
    Foo& operator=(Foo foo)
    {
        std::cout << "overload 1" << std::endl;
        return *this;
    }

    Foo& operator=(Foo&& foo)
    {
        std::cout << "overload 2" << std::endl;
        return *this;
    }

};

int main() {
    
    Foo x, x1, x2;
    // x2 = std::move(x);
    
    return 0;
}