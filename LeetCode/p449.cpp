/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        serializeHelper(root, s);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        auto front = data.c_str();
        auto begin = data.c_str();
        auto end = begin + data.size();
        _data.clear();
        while (front < end) {
            int i;
            front = from_chars(front, end, i).ptr + 1;
            _data.push_back(i);
        }
        return deserializeHelper(0, _data.size());
    }

private:
    vector<int> _data;

    void serializeHelper(TreeNode *node, string &s) {
        if (node == nullptr)
            return;
        s.append(to_string(node->val));
        s.push_back(',');
        serializeHelper(node->left, s);
        serializeHelper(node->right, s);
    }

    TreeNode *deserializeHelper(int left, int right) {
        if (left == right)
            return nullptr;
        auto node = new TreeNode(_data[left]);
        int left_start = left + 1;
        int p = left_start;
        for (; p < right && _data[p] < _data[left]; ++p) {}
        int left_end = p;
        node->left = deserializeHelper(left_start, left_end);
        node->right = deserializeHelper(left_end, right);
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;

