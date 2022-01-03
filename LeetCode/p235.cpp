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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        TreeNode *bigger_node, *smaller_node;
        if (p->val > q->val) {
            bigger_node = p;
            smaller_node = q;
        } else {
            bigger_node = q;
            smaller_node = p;
        }

        while (root->val > bigger_node->val || root->val < smaller_node->val) {
            if (root->val > bigger_node->val)
                root = root->left;
            else if (root->val < smaller_node->val)
                root = root->right;
        }
        return root;
    }
};

