class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() = default;

    void addNum(int num) {
        auto upper = upper_bound(data.begin(), data.end(), num);
        data.insert(upper, num);
    }

    double findMedian() {
        int sz = data.size();
        if (sz == 0)
            return 0;
        int step = sz / 2;
        auto it = data.begin();
        if (sz & 1) {   // odd
            for (int i = 0; i < step; ++i, ++it)
                ;
            return static_cast<double> (*it);
        } else {
            for (int i = 0; i < step; ++i, ++it)
                ;
            return (double)((*it) + (*--it)) / 2;
        }
    }

private:
    list<int> data;
};
