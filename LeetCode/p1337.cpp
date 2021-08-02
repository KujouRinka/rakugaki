#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    struct cmp {
        bool operator() (const pair<int, int> &lhs, const pair<int, int> &rhs) {
            if (lhs.first != rhs.first)
                return lhs.first < rhs.first;
            return lhs.second < rhs.second;
        }
    };
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> hp;
        for (int i = 0; i < m; ++i) {
            int start = 0;
            int end = n - 1;
            while (start < end) {
                int mid = (start + end + 1) >> 1;
                if (mat[i][mid] == 1)
                    start = mid;
                else
                    end = mid - 1;
            }
            int cur = mat[i][end] == 1 ? end + 1 : end;
            if (hp.size() == k && hp.top().first > cur)
                hp.pop();
            if (hp.size() < k)
                hp.push(make_pair(cur, i));
        }
        vector<int> result(k);
        int index = k - 1;
        while (!hp.empty()) {
            result[index--] = hp.top().second;
            hp.pop();
        }
        return result;
    }
};
