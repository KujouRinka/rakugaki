class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() = default;

    void push(int x) {
        logStack.push(x);
        if (auxStack.empty() || x <= auxStack.top())
            auxStack.push(x);
    }

    void pop() {
        if (!auxStack.empty() && logStack.top() == auxStack.top())
            auxStack.pop();
        logStack.pop();
    }

    int top() {
        return logStack.top();
    }

    int min() {
        if (auxStack.empty())
            return -1;
        return auxStack.top();
    }

private:
    stack<int> logStack;
    stack<int> auxStack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */
 