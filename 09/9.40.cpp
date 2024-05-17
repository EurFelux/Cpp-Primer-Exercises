#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    constexpr int n = 1048;
    vector<string> svec;
    svec.reserve(1024);

    cout << "capacity: " << svec.capacity() << "\tsize: " << svec.size() << endl;
    
    for (int i = 0; i < n; ++i)
        svec.push_back("test");

    cout << "capacity: " << svec.capacity() << "\tsize: " << svec.size() << endl;

    svec.resize(svec.size() + svec.size() / 2);
    cout << "capacity: " << svec.capacity() << "\tsize: " << svec.size() << endl;
    
    return 0;
}
