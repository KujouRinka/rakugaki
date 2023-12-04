class Solution {
 public:
  TreeNode *bstToGst(TreeNode *root) {
    if (root == nullptr) {
      return nullptr;
    }
    bstToGst(root->right);
    last_val = (root->val += last_val);
    bstToGst(root->left);
    return root;
  }

  int last_val = 0;
};

