#include <vector>
#include <iostream>

using iter_type = std::vector<int>::iterator;

bool find(iter_type beg, iter_type end, int val) {
    for (auto it = beg; it != end; ++it) {
        if (*it == val)
            return true;
    }
    return false;
}

int main(int argc, char const *argv[])
{
    std::vector<int> vec{1,2,3,4,5};
    bool res = find(std::begin(vec), std::end(vec), 3);
    std::cout << "result: " << res << std::endl;
    return 0;
}
