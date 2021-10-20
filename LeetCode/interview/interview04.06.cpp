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
    TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p) {
        TreeNode *pre = nullptr;
        TreeNode *now = root;
        int target = p->val;
        while (now->val != target) {
            if (now->val > target) {
                pre = now;
                now = now->left;
            } else {
                now = now->right;
            }
        }

        if (now->right == nullptr)
            return pre;
        now = now->right;
        while (now->left != nullptr)
            now = now->left;
        return now;
    }
};
