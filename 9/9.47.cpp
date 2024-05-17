/*写一个版本得了，挺麻烦的。*/

#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    string s1{"ab2c3d7R4R6"};
    string nums{"0123456789"};
    string alpha{"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};

    vector<string::size_type> poss;
    using poss_size_t = vector<string::size_type>::size_type;

    auto pos{static_cast<string::size_type>(0)};
    while (pos != s1.size())
    {
        pos = s1.find_first_of(nums, pos);
        if (pos != string::npos)
        {
            poss.push_back(pos);
            pos += 1;
        }
        else
        {
            break;
        }
    }

    for (poss_size_t i = 0; i < poss.size(); ++i)
    {
        cout << poss[i] << " ";
    }
    cout << endl;

    poss.clear();
    pos = 0;

    while (pos != s1.size())
    {
        pos = s1.find_first_of(alpha, pos);
        if (pos != string::npos)
        {
            poss.push_back(pos);
            pos += 1;
        }
        else
        {
            break;
        }
    }

    for (poss_size_t i = 0; i < poss.size(); ++i)
    {
        cout << poss[i] << " ";
    }
    cout << endl;

    return 0;
}
