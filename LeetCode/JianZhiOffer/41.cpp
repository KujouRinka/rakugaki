class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() : _min_hp(f) {}

    void addNum(int num) {
        if (_max_hp.empty() || num < _max_hp.top())
            _max_hp.push(num);
        else
            _min_hp.push(num);
        if (int(_max_hp.size()) - int(_min_hp.size()) > 1) {
            _min_hp.push(_max_hp.top());
            _max_hp.pop();
        }
        if (int(_min_hp.size()) - int(_max_hp.size()) > 1) {
            _max_hp.push(_min_hp.top());
            _min_hp.pop();
        }
    }

    double findMedian() {
        if (_max_hp.size() == _min_hp.size())
            return (_max_hp.top() + _min_hp.top()) / 2.0;
        else
            return _max_hp.size() > _min_hp.size() ? _max_hp.top() : _min_hp.top();
    }

private:

    static bool f(int l, int r) {
        return l > r;
    }
    priority_queue<int> _max_hp;
    priority_queue<int, vector<int>, function<bool(int, int)>> _min_hp;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

