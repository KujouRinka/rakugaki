/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    bool checkSubTree(TreeNode *t1, TreeNode *t2) {
        _t2 = t2;
        return check(t1);
    }

private:
    TreeNode *_t2;

    bool check(TreeNode *t1) {
        if (t1 == nullptr)
            return false;
        if (checkSub(t1, _t2))
            return true;
        if (check(t1->left))
            return true;
        return check(t1->right);
    }

    bool checkSub(TreeNode *head, TreeNode *h2) {
        if (h2 == nullptr)
            return true;
        if (head->val != h2->val)
            return false;
        return checkSub(head->left, h2->left) && checkSub(head->right, h2->right);
    }
};

