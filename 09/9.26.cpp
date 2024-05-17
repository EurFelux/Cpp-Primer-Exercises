#include <vector>
#include <list>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
    vector<int> vec(begin(ia), end(ia));
    list<int> lst(begin(ia), end(ia));

    for (auto iter = vec.begin(); iter != vec.end();) {
        if (*iter % 2 == 0)
            iter = vec.erase(iter);
        else
            ++iter;
    }

    for (auto iter = lst.begin(); iter != lst.end();) {
        if (*iter % 2 == 1)
            iter = lst.erase(iter);
        else
            ++iter;
    }

    for (auto num: vec)
        cout << num << " ";
    cout << endl;

    for (auto num: lst)
        cout << num << " ";
    cout << endl;

    return 0;
}