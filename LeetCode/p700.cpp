class Solution {
public:
    TreeNode *searchBST(TreeNode *root, int val) {
        if (root == nullptr)
            return nullptr;
        if (root->val > val)
            return searchBST(root->left, val);
        if (root->val < val)
            return searchBST(root->right, val);
        if (root->val == val)
            return root;
        return nullptr;
    }
};
