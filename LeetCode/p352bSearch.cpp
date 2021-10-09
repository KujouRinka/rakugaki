class SummaryRanges {
public:
    SummaryRanges() = default;

    void addNum(int val) {
        auto interval_behind = intervals.upper_bound(val);
        auto interval_front = (interval_behind == intervals.begin() ? intervals.end() : prev(interval_behind));
        if (interval_front == interval_behind) {
            intervals[val] = val;
            return;
        }

        if (interval_behind == intervals.begin()) {
            if (val == interval_behind->first) { ;
            } else if (interval_behind->first - val == 1) {
                int tmp = interval_behind->second;
                intervals.erase(interval_behind);
                intervals[val] = tmp;
            } else {
                intervals.insert(interval_behind, {val, val});
            }
        } else if (interval_behind == intervals.end()) {
            if (val <= interval_front->second) { ;
            } else if (val - interval_front->second <= 1) {
                interval_front->second = val;
            } else {
                intervals.insert(interval_behind, {val, val});
            }
        } else {
            if (val == interval_behind->first) {
                return;
            } else if (val <= interval_front->second) {
                return;
            }

            if (val - interval_front->second <= 1) {
                interval_front->second = val;
                if (interval_behind->first - val == 1) {
                    interval_front->second = interval_behind->second;
                    intervals.erase(interval_behind);
                }
            } else if (interval_behind->first - val == 1) {
                int tmp = interval_behind->second;
                intervals.erase(interval_behind);
                intervals[val] = tmp;
            } else {
                intervals.insert(interval_behind, {val, val});
            }
        }
    }

    vector<vector<int>> getIntervals() {
        vector<vector<int>> result;
        for (auto &i: intervals)
            result.push_back({i.first, i.second});
        return result;
    }

private:
    map<int, int> intervals;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
