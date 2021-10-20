class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() = default;

    void push(int x) {
        if (m_min_stack.empty() || x <= m_min_stack.top())
            m_min_stack.push(x);
        m_data_stack.push(x);
    }

    void pop() {
        if (m_data_stack.top() == m_min_stack.top())
            m_min_stack.pop();
        m_data_stack.pop();
    }

    int top() {
        return m_data_stack.top();
    }

    int getMin() {
        return m_min_stack.top();
    }

private:
    stack<int> m_data_stack;
    stack<int> m_min_stack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
