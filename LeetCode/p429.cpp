/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (root == nullptr)
            return {};
        vector<vector<int>> result;
        queue<Node *> q;
        q.push(root);
        vector<int> tv;
        while (!q.empty()) {
            tv.clear();
            for (int i = q.size(); i > 0; --i) {
                auto n = q.front();
                q.pop();
                tv.push_back(n->val);
                for (auto nn: n->children) {
                    if (nn != nullptr)
                        q.push(nn);
                }
            }
            result.push_back(tv);
        }
        return result;
    }
};

