#include <vector>
#include <iostream>

using iter_type = std::vector<int>::iterator;

iter_type find(iter_type beg, iter_type end, int val) {
    for (auto it = beg; it != end; ++it) {
        if (*it == val)
            return it;
    }
    return end;
}

int main(int argc, char const *argv[])
{
    std::vector<int> vec{1,2,3,4,5};
    iter_type res = find(std::begin(vec), std::end(vec), 0);
    std::vector<int>::value_type a{5};
    if (res != std::end(vec))
        std::cout << "result: " << *res << std::endl;
    else
        std::cout << "cannot find." << std::endl;
    return 0;
}
