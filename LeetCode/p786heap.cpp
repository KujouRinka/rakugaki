class Solution {
public:
    vector<int> kthSmallestPrimeFraction(const vector<int> &arr, int k) {
        auto f = [&arr](const pair<int, int> &lhs, const pair<int, int> &rhs) -> bool {
            return arr[lhs.second] * arr[rhs.first] < arr[lhs.first] * arr[rhs.second];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(f)> heap(f);
        int sz = arr.size();
        for (int i = 0; i < sz; ++i)
            heap.emplace(0, i);
        for (int i = 1; i < k; ++i) {
            auto[x, y] = heap.top();
            heap.pop();
            if (x + 1 < y)
                heap.emplace(x + 1, y);
        }
        return {arr[heap.top().first], arr[heap.top().second]};
    }
};
