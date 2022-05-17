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
    bool isBalanced(TreeNode *root) {
        auto[stat, _] = helper(root);
        return stat;
    }

private:
    pair<bool, int> helper(TreeNode *root) {
        if (root == nullptr)
            return {true, 0};
        auto[s1, ld] = helper(root->left);
        auto[s2, rd] = helper(root->right);
        return {s1 && s2 && abs(ld - rd) <= 1, max(ld, rd) + 1};
    }
};

