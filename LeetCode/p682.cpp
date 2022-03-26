class Solution {
public:
    int calPoints(const vector<string>& ops) {
        int points = 0;
        int sz = ops.size();
        vector<int> points_record;
        for (int i = 0; i < sz; ++i) {
            if (ops[i] == "C") {
                points_record.pop_back();
            } else if (ops[i] == "D") {
                points_record.push_back(points_record.back() * 2);
            } else if (ops[i] == "+") {
                points_record.push_back(points_record.back() + points_record[points_record.size() - 2]);
            } else {
                points_record.push_back(stoi(ops[i]));
            }
        }
        return accumulate(points_record.begin(), points_record.end(), 0);
    }
};

