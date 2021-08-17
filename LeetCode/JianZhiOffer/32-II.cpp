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
    vector<vector<int>> levelOrder(TreeNode *root) {
        queue<TreeNode *> waitQueue;
        vector<vector<int>> result;
        waitQueue.push(root);

        int stackQuan = 1;
        int visitedQuan = 0;
        vector<int> tmp;
        while (!waitQueue.empty()) {
            if (stackQuan == visitedQuan) {
                visitedQuan = 0;
                stackQuan = waitQueue.size();
                result.push_back(tmp);
                tmp.clear();
            }

            TreeNode *now = waitQueue.front();
            waitQueue.pop();
            visitedQuan++;
            if (now != nullptr) {
                tmp.push_back(now->val);
                waitQueue.push(now->left);
                waitQueue.push(now->right);
            }
        }
        return result;
    }
};
