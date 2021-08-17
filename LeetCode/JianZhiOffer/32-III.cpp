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
        bool isReverse = false;
        vector<int> tmp;
        while (!waitQueue.empty()) {
            if (stackQuan == visitedQuan) {
                visitedQuan = 0;
                stackQuan = waitQueue.size();
                if (isReverse)
                    result.emplace_back(tmp.rbegin(), tmp.rend());
                else
                    result.emplace_back(tmp.begin(), tmp.end());
                tmp.clear();
                isReverse = !isReverse;
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
