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
    bool isSubStructure(TreeNode *A, TreeNode *B) {
        if (B == nullptr)
            return false;
        _B = B;
        return visit(A);
    }

private:
    TreeNode *_B;
    bool visit(TreeNode *node) {
        if (node == nullptr)
            return false;
        return isSame(node, _B) || visit(node->left) || visit(node->right);
    }

    bool isSame(TreeNode *head, TreeNode *B) {
        if (B == nullptr)
            return true;
        if (head == nullptr)
            return false;
        if (head->val != B->val)
            return false;
        return isSame(head->left, B->left) && isSame(head->right, B->right);
    }
};

