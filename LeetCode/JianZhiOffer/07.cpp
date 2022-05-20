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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        for (int i = 0; i < inorder.size(); ++i)
            _m[inorder[i]] = i;
        return makeHelper(preorder, inorder, 0, preorder.size(), 0, inorder.size());
    }

private:
    unordered_map<int, int> _m;
    TreeNode *makeHelper(
        vector<int> &pre, vector<int> &in,
        int pre_f, int pre_b, int in_f, int in_b
    ) {
        if (pre_f == pre_b)
            return nullptr;
        auto new_node = new TreeNode(pre[pre_f]);
        int in_split = _m[pre[pre_f]];
        new_node->left = makeHelper(pre, in, pre_f + 1, pre_f + 1 + in_split - in_f, in_f, in_split);
        new_node->right = makeHelper(pre, in, pre_f + 1 + in_split - in_f, pre_b, in_split + 1, in_b);
        return new_node;
    }
};

