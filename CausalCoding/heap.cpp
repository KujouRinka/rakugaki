#include <iostream>
#include <vector>

using namespace std;

class heap {
public:
    heap() = default;
    void push(int value);
    void pop();
    int top() const;
    bool empty() const;

private:
    vector<int> data;
    int size = 0;
    int next = 1;
    static int parentOf(int index);
    static int rightChild(int index);
    inline static void swap(int &a, int &b);
};

void heap::push(int value) {
    if (next >= data.size())
        data.resize(next * 2);
    data[next] = value;

    int ind = next;
    while (ind != 1) {
        if (data[ind] >= data[parentOf(ind)])
            break;
        swap(data[ind], data[parentOf(ind)]);
        ind = parentOf(ind);
    }
    ++next;
    ++size;
}

void heap::pop() {
    if (size == 0)
        throw runtime_error("pop on a empty heap");
    swap(data[size], data[1]);
    next--;
    --size;
    int ind = 1;
    while (true) {
        int left = rightChild(ind) - 1;
        int right = rightChild(ind);
        if (left > size) {  // 左右两子节点不存在
            break;
        } else if (right > size) {    // 右节点不存在
            if (data[ind] > data[left]) swap(data[ind], data[left]);
            else break;
            ind = left;
        } else {
            int leftVal = data[left];
            int rightVal = data[right];
            if (leftVal <= rightVal && leftVal < data[ind]) {
                swap(data[ind], data[left]);
                ind = left;
            } else if (rightVal < leftVal && rightVal < data[ind]) {
                swap(data[ind], data[right]);
                ind = right;
            } else break;
        }
    }
}

int heap::top() const {
    if (size == 0)
        throw runtime_error("top on a empty heap");
    return data[1];
}

bool heap::empty() const {
    return size == 0;
}

int heap::parentOf(int index) {
    return index / 2;
}

int heap::rightChild(int index) {
    return index * 2 + 1;
}

inline void heap::swap(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}
