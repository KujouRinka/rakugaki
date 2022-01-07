class Solution {
public:
    int maxDepth(const string &s) {
        int depth = 0;
        int max_depth = 0;
        for (char ch: s) {
            if (ch == '(')
                ++depth;
            else if (ch == ')')
                --depth;
            
            max_depth = max(max_depth, depth);
        }

        return max_depth;
    }
};

