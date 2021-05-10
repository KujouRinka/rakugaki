// 此程序为该习题的参考答案，某些函数的实现有大问题
#include <iostream>
#include <string>

using namespace std;

class TreeNode {

public:
    TreeNode() :
            value(""), count(1), left(nullptr), right(nullptr) {}

    TreeNode(const string &s = string(), TreeNode *lChild = nullptr, TreeNode *rChild = nullptr) :
            value(s), count(1), left(lChild), right(rChild) {}

    TreeNode(const TreeNode &tn);

    void CopyTree();

    int ReleaseTree();

    ~TreeNode();

private:
    string value;
    int count;
    TreeNode *left;
    TreeNode *right;
};


class BinStrTree {

public:
    BinStrTree() : root(nullptr) {}

    BinStrTree(TreeNode *t = nullptr) : root(t) {}

    BinStrTree(const BinStrTree &bst);

    ~BinStrTree();

private:
    TreeNode *root;
};

void TreeNode::CopyTree() {
    ++count;
    if (left != nullptr)
        left->CopyTree();
    if (right != nullptr)
        right->CopyTree();
}

TreeNode::TreeNode(const TreeNode &tn) :
        value(tn.value), count(1), left(tn.left), right(tn.right) {
    if (left != nullptr)
        left->CopyTree();
    if (right != nullptr)
        right->CopyTree();
}

int TreeNode::ReleaseTree() {
    if (left != nullptr)
        if (!left->ReleaseTree())
            delete left;
    if (right != nullptr)
        if (!right->ReleaseTree())
            delete right;
    --count;
    return count;
}

TreeNode::~TreeNode() {
    if (count)
        ReleaseTree();
}


BinStrTree::BinStrTree(const BinStrTree &bst) : root(bst.root) {
    root->CopyTree();
}

BinStrTree::~BinStrTree() {
    if (!root->ReleaseTree())
        delete root;
}
