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
    vector<int> levelOrder(TreeNode *root) {
        queue<TreeNode *> waitQueue;
        vector<int> result;
        waitQueue.push(root);
        while (!waitQueue.empty()) {
            TreeNode *now = waitQueue.front();
            waitQueue.pop();
            if (now != nullptr) {
                result.push_back(now->val);
                waitQueue.push(now->left);
                waitQueue.push(now->right);
            }
        }
        return result;
    }
};
