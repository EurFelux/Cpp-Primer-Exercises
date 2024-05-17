#include <forward_list>
#include <iostream>

int main(int argc, char const *argv[])
{
    using namespace std;

    forward_list<int> lst{1, 2, 3, 4, 5};

    auto prev = lst.before_begin();
    auto curr = lst.begin();

    /* 启发：对于forward_list，插入不会使得任何迭代器失效，删除只会令被删除的位置迭代器失效。*/

    while (curr != lst.end()) {
        if (*curr % 2 == 1) {
            curr = lst.erase_after(prev);
        } else {
            ++prev;
            ++curr;
        }
    }

    for (auto num: lst) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}