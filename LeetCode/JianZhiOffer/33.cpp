class Solution {
public:
    bool verifyPostorder(vector<int> &postorder) {
        return helper(postorder, 0, postorder.size());
    }

private:
    bool helper(vector<int> &po, int l, int r) {
        if (l == r)
            return true;
        int node = po[r - 1];
        int nr2 = r - 1;
        int nr1 = r - 1;
        while (nr1 - 1 >= l && po[nr1 - 1] > node)
            --nr1;
        int nl2 = nr1;
        int nl1 = l;
        for (int i = nl1; i < nl2; ++i)
            if (po[i] > node)
                return false;
        return helper(po, nl1, nl2) && helper(po, nr1, nr2);
    }
};

