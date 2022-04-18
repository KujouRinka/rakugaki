class Solution {
public:
    vector<int> lexicalOrder(int n) {
        _n = n;
        backtracking(0, 1);
        return _result;
    }

private:
    int _n;
    vector<int> _result;

    void backtracking(int val, int start) {
        if (val > _n)
            return;
        if (val > 0)
            _result.push_back(val);
        for (int i = start; i < 10; ++i) {
            val *= 10;
            val += i;
            backtracking(val, 0);
            val /= 10;
        }
    }
};

