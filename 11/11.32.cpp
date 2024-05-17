#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>

using namespace std;

// 像这种时候就会觉得，还是map<Author, vector<AuthorWork>>好。起码我可以直接给vector排序。
int main() {
    using Author = string;
    using AuthorWork = string;
    
    multimap<Author, AuthorWork> mm{
        {"Shakespeare", "Hamlet"},
        {"Shakespeare", "Romeo and Juliet"},
        {"Shakespeare", "Macbeth"},
        {"Austen", "Pride and Prejudice"},
        {"Austen", "Sense and Sensibility"},
        {"Dostoevsky", "Crime and Punishment"},
        {"Dostoevsky", "The Brothers Karamazov"}
    };

    auto ex_it = mm.begin();
    auto pre_it = mm.cend();
    while (ex_it != mm.cend()) {
        // find a valid key
        const Author& author = ex_it->first;
        if (pre_it != mm.cend() && author == pre_it->first) {
            continue;
        } else {
            cout << author << endl;
            const auto range = mm.equal_range(author);
            vector<AuthorWork> vec;
            for (auto it = range.first; it != range.second; ++it) {
                vec.push_back(it->second);
            }
            sort(vec.begin(), vec.end());
            for (const auto& item : vec) {
                cout << "\t" << item << endl;
            }
            pre_it = ex_it;
            ex_it = range.second;
        }
    }
    return 0;
}