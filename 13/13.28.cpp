#include <iostream>

using namespace std;

class TreeNode {
public:
    TreeNode() : value(""), count(0), left(nullptr), right(nullptr) {}
    TreeNode(const TreeNode&) = default;
    TreeNode& operator=(const TreeNode&) = default;
    ~TreeNode() = default;

private:
    string value;
    int count;
    TreeNode *left;
    TreeNode *right;
};

// 需求不明确，我不想写了。
class BinStrTree {
public:
    BinStrTree() : root(new TreeNode()) {}
    BinStrTree(const BinStrTree&) = default;
    BinStrTree& operator=(const BinStrTree&) = default;
    ~BinStrTree();

private:
    TreeNode *root;
};

int main() {
    
    return 0;
}