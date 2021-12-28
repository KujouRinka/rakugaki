class MyQueue {
public:
    MyQueue() : peek_val(-1) {};

    void push(int x) {
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
        s1.push(x);
        if (s1.size() == 1)
            peek_val = x;
    }

    int pop() {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        int v = s2.top();
        s2.pop();
        if (!s2.empty())
            peek_val = s2.top();
        return v;
    }

    int peek() {
        return peek_val;
    }

    bool empty() {
        return s1.empty() && s2.empty();
    }

private:
    stack<int> s1;
    stack<int> s2;
    int peek_val;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

