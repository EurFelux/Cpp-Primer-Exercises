#include <vector>
#include <list>
#include <iostream>

int main(int argc, char const *argv[])
{
    using std::vector, std::list;

    vector<int> vec{1, 2, 3};
    list<int> lst{1, 2, 3};
    
    vec.insert(vec.end(), lst.begin(), lst.end());

    // 不同容器类型不能够直接使用 == 比较，所以需要手动实现。麻烦。哈哈，懒得实现了。
    // std::cout << (vec == lst) << std::endl;


    return 0;
}
