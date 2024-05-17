#include <list>
#include <vector>

int main(int argc, char const *argv[])
{
    using std::list, std::vector;
    
    // 启发：值类型可隐式转换，“相容”即可，并不要求完全相同
    
    // task 1: 
    list<int> l1{1, 2, 3};
    
    vector<double> r1{l1.begin(), l1.end()};
    
    // task 2:
    vector<int> l2{3, 2, 1};
    vector<double> r2{l2.begin(), l2.end()};

    return 0;
}
