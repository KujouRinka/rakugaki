class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() = default;

    void addNum(int num) {
        if (minHeap.empty() || num <= minHeap.top()) {
            minHeap.push(num);
        } else {
            maxHeap.push(num);
        }

        if (minHeap.size() > maxHeap.size() + 1) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        } else if (minHeap.size() < maxHeap.size()) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
    }

    double findMedian() {
        return minHeap.size() == maxHeap.size() ?
               static_cast<double>(minHeap.top() + maxHeap.top()) / 2 :
               static_cast<double>(minHeap.top());
    }

private:
    priority_queue<int, vector<int>, less<int>> minHeap;
    priority_queue<int, vector<int>, greater<int>> maxHeap;
};
