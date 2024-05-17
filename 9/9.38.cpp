#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> vec;
    cout << "capacity: " << vec.capacity() << "\tsize: " << vec.size() << endl;

    int num = 0;
    while(cin >> num) {
        vec.push_back(num);
        cout << "capacity: " << vec.capacity() << "\tsize: " << vec.size() << endl;
    }

    return 0;
}
