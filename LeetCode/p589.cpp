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
    using PC = int;
    using FP = pair<tuple<Node *, int>, PC>;
    vector<int> preorder(Node *root) {
        if (root == nullptr)
            return {};
        vector<int> r;
        stack<FP> st;
        FP SP = {{root, 0}, 0};
        Node *AX;
        while (!st.empty() || SP.second != 5) {
            switch (SP.second) {
                case 0:
                    if (get<0>(SP.first) == nullptr)
                        ++SP.second;
                    else
                        SP.second = 2;
                    break;
                case 1:
                    SP = st.top();
                    st.pop();
                    break;
                case 2:
                    r.push_back(get<0>(SP.first)->val);
                    ++SP.second;
                    break;
                case 3:
                    if (get<1>(SP.first) == get<0>(SP.first)->children.size()) {
                        SP.second = 5;
                    } else {
                        AX = get<0>(SP.first)->children[get<1>(SP.first)];
                        SP.second = 4;
                    }
                    break;
                case 4:
                    SP.second = 3;
                    ++get<1>(SP.first);
                    st.push(SP);
                    SP = {{AX, 0}, 0};
                    break;
                case 5:
                    SP = st.top();
                    st.pop();
                    break;
                default:
                    break;
            }
        }
        return r;
    }
};

