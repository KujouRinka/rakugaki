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
  TreeNode *lcaDeepestLeaves(TreeNode *root) {
    if (root == nullptr) {
      return nullptr;
    }
    int d;
    return helper(root, d);
  }

 private:
  TreeNode *helper(TreeNode *node, int &depth) {
    if (node == nullptr) {
      depth = 0;
      return nullptr;
    }
    int dl, dr;
    auto *n1 = helper(node->left, dl);
    auto *n2 = helper(node->right, dr);
    if (dl == dr) {
      depth = dl + 1;
      return node;
    } else if (dl > dr) {
      depth = dl + 1;
      return n1;
    } else {
      depth = dr + 1;
      return n2;
    }
  }
};

