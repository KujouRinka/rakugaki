class Solution {
public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, int> freq_counter;
        for (int i: nums)
            ++freq_counter[i];
        auto f = [&freq_counter](int lhs, int rhs) -> bool {
            return freq_counter[lhs] > freq_counter[rhs];
        };

        priority_queue<int, vector<int>, decltype(f)> hp(f);
        auto m_it = freq_counter.begin();
        for (int i = 0; i < k; ++i)
            hp.push(m_it++->first);

        int sz = nums.size();
        for (; m_it != freq_counter.end(); ++m_it) {
            if (m_it->second > freq_counter[hp.top()]) {
                hp.pop();
                hp.push(m_it->first);
            }
        }

        vector<int> result;
        result.reserve(hp.size());
        while (!hp.empty()) {
            result.push_back(hp.top());
            hp.pop();
        }
        return result;
    }
};

