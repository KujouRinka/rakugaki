class Solution {
public:
    int findMaximizedCapital(int k, int w, const vector<int> &profits, const vector<int> &capital) {
        priority_queue<int> validProfit;
        vector<pair<int, int>> dataPair;
        auto sz = capital.size();
        int ptr = 0;

        for (int i = 0; i < sz; ++i)
            dataPair.emplace_back(capital[i], profits[i]);
        sort(dataPair.begin(), dataPair.end());
        while (k--) {
            while (ptr < sz && dataPair[ptr].first <= w) {
                validProfit.push(dataPair[ptr].second);
                ++ptr;
            }
            if (validProfit.empty())
                break;
            w += validProfit.top();
            validProfit.pop();
        }

        return w;
    }
};
