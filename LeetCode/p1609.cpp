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
    bool isEvenOddTree(TreeNode *root) {
        if (root == nullptr)
            return false;
        queue<TreeNode *> node_queue;
        node_queue.push(root);
        int this_node_num = 1;
        int layer = 0;
        while (!node_queue.empty()) {
            int next_node_num = 0;

            int previous_value = (layer & 1) ? 0x7fffffff : 0;
            int this_value = -1;
            while (this_node_num--) {
                TreeNode *this_node = node_queue.front();
                node_queue.pop();
                this_value = this_node->val;
                if (!((layer & 1)
                      ? (previous_value > this_value && !(this_value & 1))
                      : (previous_value < this_value && (this_value & 1))))
                    return false;

                this_node->left == nullptr ? 0 : (node_queue.push(this_node->left), ++next_node_num);
                this_node->right == nullptr ? 0 : (node_queue.push(this_node->right), ++next_node_num);
                previous_value = this_value;
            }
            this_node_num = next_node_num;
            ++layer;
        }

        return true;
    }
};

