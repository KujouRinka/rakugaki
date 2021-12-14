class Solution {
public:
    int scheduleCourse(vector<vector<int>> &courses) {
        sort(courses.begin(), courses.end(), [](const vector<int> &lhs, const vector<int> &rhs) -> bool {
            return lhs[1] < rhs[1];
        });
        priority_queue<int> hp;
        int time_sum = 0;
        for (auto &v: courses) {
            if (time_sum + v[0] <= v[1]) {
                time_sum += v[0];
                hp.push(v[0]);
            } else if (!hp.empty() && hp.top() > v[0]) {
                time_sum += (v[0] - hp.top());
                hp.pop();
                hp.push(v[0]);
            }
        }
        return hp.size();
    }
};

