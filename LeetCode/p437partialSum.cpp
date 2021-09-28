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
private:
    int count = 0;
    int target = 0;
    unordered_map<int, int> cntMap = {{0, 1}};
    void addMap(int i) {
        ++cntMap[i];
    }

    void minusMap(int i) {
        --cntMap[i];
    }

    void dfs(TreeNode *root, int sum) {
        if (root == nullptr)
            return;
        int nowSum = sum + root->val;
        count += cntMap[nowSum - target];
        addMap(nowSum);
        dfs(root->left, nowSum);
        dfs(root->right, nowSum);

        minusMap(nowSum);
    }

public:
    int pathSum(TreeNode *root, int targetSum) {
        target = targetSum;
        dfs(root, 0);
        return count;
    }
};
