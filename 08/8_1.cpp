#include <iostream>
#include <fstream>
#include <cassert>

using std::istream;
using std::cout;
using std::endl;

class Solution {
private:

public:
    istream &exer_1(istream &is) {
        int num{0};
        while (is >> num) {
            cout << num << endl;
        }
        is.clear();
        return is;
    }

    void exer_2() {
        exer_1(std::cin);
    }

    void test_1() {
        using std::cin;
        using std::endl;
        // 无参数重载，返回关联的流
        auto o1 = cin.tie();

        // 带参数重载。给一个ostream指针，为输入流关联输出流。返回值为之前关联的流的指针。
        auto o2 = cin.tie(&cout); // 无意义，cin默认关联cout
        cout << (&cout == o2) << endl;

        auto o3 = cin.tie(nullptr);
        cout << (&cout == o3) << endl;
    }

    void test_2() {
        using std::cin;
        using std::ifstream;
        ifstream in("test.txt");
        assert(in.is_open());
        in.tie(nullptr);
        cout << "Result:" << endl;
        in.setstate(in.badbit | in.eofbit);
        // cin.clear(cin.badbit | cin.eofbit);
        cout << in.rdstate() << endl;
        in.clear(in.badbit);
        // cin.setstate(cin.failbit);
        cout << in.rdstate() << endl;

    }
};

int main() {
    Solution sol;
    sol.test_2();
    return 0;
}