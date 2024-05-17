#include <list>
#include <deque>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    list<int> lst{1, 2, 3, 4, 5};
    deque<int> q_odd, q_even;

    for (auto num: lst) {
        if (num % 2 == 0)
            q_even.emplace_back(num);
        else
            q_odd.emplace_back(num);
    }

    cout << "q_odd: ";
    for (auto num: q_odd) {
        cout << num << " ";
    }
    cout << endl;

    cout << "q_evem: ";
    for (auto num: q_even) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}