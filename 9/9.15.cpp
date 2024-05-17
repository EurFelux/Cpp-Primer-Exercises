#include <vector>
#include <iostream>

int main(int argc, char const *argv[])
{
    using std::vector;

    vector<int> v1{1, 2, 3};
    vector<int> v2{1, 2, 3};
    vector<int> v3{3, 2, 1};
    std::cout << (v1 == v2) << std::endl;
    std::cout << (v1 == v3) << std::endl;
    return 0;
}
