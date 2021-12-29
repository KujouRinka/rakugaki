class MaxQueue {
public:
    MaxQueue() = default;

    void push(int v) {
        q.push(v);
        while (!dq.empty() && dq.back() < v)
            dq.pop_back();
        dq.push_back(v);
    }

    void pop() {
        if (q.front() == dq.front())
            dq.pop_front();
        q.pop();
    }

    int max() {
        return dq.front();
    }

private:
    queue<int> q;
    deque<int> dq;
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        MaxQueue m_queue;
        int sz = nums.size();

        vector<int> result;
        result.reserve(sz - k + 1);
        for (int i = 0; i < k; ++i)
            m_queue.push(nums[i]);
        result.push_back(m_queue.max());
        for (int i = k; i < sz; ++i) {
            m_queue.pop();
            m_queue.push(nums[i]);
            result.push_back(m_queue.max());
        }

        return result;
    }
};

