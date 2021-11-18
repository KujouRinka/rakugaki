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
    int findTilt(TreeNode *root) {
        tilt = 0;
        nodeSum(root);
        return tilt;
    }

private:
    int tilt = 0;
    int nodeSum(TreeNode *head) {
        if (head == nullptr)
            return 0;
        int left_sum = nodeSum(head->left);
        int right_sum = nodeSum(head->right);
        tilt += abs(left_sum - right_sum);
        return left_sum + right_sum + head->val;
    }
};
