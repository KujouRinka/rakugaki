class SummaryRanges {
public:
    SummaryRanges() = default;

    void addNum(int val) {
        auto it = this->data.begin();
        for (it = this->data.begin(); it != this->data.end() && *it < val; ++it);
        if (it == this->data.end() || *it != val)
            data.insert(it, val);
    }

    vector<vector<int>> getIntervals() {
        int start;
        int end;
        vector<vector<int>> result;
        for (auto it = this->data.begin(); it != this->data.end();) {
            start = end = *it;
            while (true) {
                auto lastIt = it;
                ++it;
                if (it == this->data.end() || *it - *lastIt > 1)
                    break;
                end = *it;
            }
            result.push_back({start, end});
        }

        return result;
    }

private:
    list<int> data;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
