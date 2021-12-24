class Solution {
public:
    int eatenApples(const vector<int> &apples, const vector<int> &days) {
        auto f = [](const pair<int, int> &lhs, const pair<int, int> &rhs) -> bool {
            return lhs.second > rhs.second;
        };

        // pair<apple_nums, last_due>
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(f)> hp(f);
        int result = 0;
        int sz = apples.size();
        for (int day = 0; day < sz || !hp.empty(); ++day) {
            if (day < sz && apples[day] != 0)
                hp.push({apples[day], day + days[day] - 1});
            while (!hp.empty()) {
                int this_apples = hp.top().first;
                int last_due = hp.top().second;
                hp.pop();
                if (last_due >= day) {
                    if (this_apples - 1 > 0)
                        hp.push({this_apples - 1, last_due});
                    ++result;
                    break;
                }
            }
        }
        return result;
    }
};

