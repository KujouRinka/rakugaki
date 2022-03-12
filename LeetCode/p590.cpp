class Solution {
public:
    using PC = int;
    using FP = pair<tuple<Node *, int>, PC>;    // FP(frame pointer) = pair<Data, PC>
    vector<int> postorder(Node *root) {
        if (root == nullptr)
            return {};
        vector<int> r;
        stack<FP> st;
        FP SP = {{root, 0}, 0};     // SP (stack pointer)
        Node *AX;
        // void dfs(Node *root) {
        //     if (root == nullptr)            <--- 0
        //         return;                     <--- 1
        //     for (auto ch: root->children)   <--- 2
        //         dfs(ch);                    <--- 3
        //     r.push_back(root->val);         <--- 4
        //     return;                         <--- 5
        // }
        while (!st.empty() || SP.second != 5) {
            switch (SP.second) {
                case 0:     // if (root == nullptr)
                    if (get<0>(SP.first) == nullptr)
                        ++SP.second;
                    else
                        SP.second = 2;
                    break;
                case 1:     // return;
                    SP = st.top();
                    st.pop();
                    break;
                case 2:     // for (auto ch: root->children)     
                    if (get<1>(SP.first) == get<0>(SP.first)->children.size()) {
                        SP.second = 4;
                    } else {
                        AX = get<0>(SP.first)->children[get<1>(SP.first)];
                        SP.second = 3;
                    }
                    break;
                case 3:     // dfs(ch);
                    SP.second = 2;
                    ++get<1>(SP.first);
                    st.push(SP);
                    SP = {{AX, 0}, 0};
                    break;
                case 4:     // r.push_back(root->val);     
                    r.push_back(get<0>(SP.first)->val);
                    ++SP.second;
                    break;
                case 5:     // return;
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

