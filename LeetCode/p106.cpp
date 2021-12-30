/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode *buildTree(const vector<int> &inorder, const vector<int> &postorder) {
        int sz = inorder.size();
        return makeTree(inorder, postorder, 0, sz, 0, sz);
    }

private:
    static TreeNode *makeTree(const vector<int> &inorder, const vector<int> &postorder,
                              int inorder_lower, int inorder_upper, int postorder_lower, int postorder_upper) {
        if (inorder_lower >= inorder_upper)
            return nullptr;
        if (inorder_lower == inorder_upper - 1)
            return new TreeNode(inorder[inorder_lower]);

        int mid_val = postorder[postorder_upper - 1];
        int new_inorder_center = findIdx(inorder, mid_val);

        int left_tree_size = new_inorder_center - inorder_lower;

        TreeNode *left_tree = makeTree(inorder, postorder, inorder_lower, new_inorder_center,
                                       postorder_lower, postorder_lower + left_tree_size);
        TreeNode *right_tree = makeTree(inorder, postorder, new_inorder_center + 1, inorder_upper,
                                        postorder_lower + left_tree_size, postorder_upper - 1);
        TreeNode *this_node = new TreeNode(mid_val);
        this_node->left = left_tree;
        this_node->right = right_tree;
        return this_node;
    }

    static int findIdx(const vector<int> &v, int target) {
        int sz = v.size();
        for (int i = 0; i < sz; ++i)
            if (v[i] == target)
                return i;
        return -1;
    }
};

