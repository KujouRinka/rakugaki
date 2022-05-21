class Solution {
public:
    int minimumOperations(const vector<int> &nums) {
        auto sz = nums.size();
        if (sz == 1)
            return 0;
        unordered_map<int, int> m1;
        unordered_map<int, int> m2;
        for (int i = 0; i < sz; ++i) {
            if (i & 1)
                ++m2[nums[i]];
            else
                ++m1[nums[i]];
        }
        auto it1 = m1.begin();
        auto it2 = m1.end();
        auto it3 = m2.begin();
        auto it4 = m2.end();
        for (auto it = next(m1.begin()); it != m1.end(); ++it) {
            if (it1->second < it->second) {
                it2 = it1;
                it1 = it;
            } else if (it1->second == it->second) {
                it2 = it;
            } else if (it2 != m1.end() && it2->second < it->second) {
                it2 = it;
            }
        }
        for (auto it = next(m2.begin()); it != m2.end(); ++it) {

            if (it3->second < it->second) {
                it4 = it3;
                it3 = it;
            } else if (it3->second == it->second) {
                it4 = it;
            } else if (it4 != m1.end() && it4->second < it->second) {
                it4 = it;
            }
        }
        if (it2 != m1.end()) {
            cout << "m2 " << it2->first << " " << it2->second << endl;
        }
        if (it4 != m2.end()) {
            cout << "m4 " << it4->first << " " << it4->second << endl;
        }

        if (it1->first == it3->first) {
            if (it2 == m1.end() && it4 == m2.end())
                return min(it1->second, it3->second);
            if (it2 == m1.end()) {
                return min(it1->second, int(sz - it1->second - it4->second));
            } else if (it4 == m2.end()) {
                return min(it3->second, int(sz - it3->second - it2->second));
            } else {
                return sz - max(it1->second + it4->second, it2->second + it3->second);
            }
        }
        return sz - it1->second - it3->second;
    }
};

