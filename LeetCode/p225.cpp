class MyStack {
public:
    MyStack() = default;

    void push(int x) {
        q.push(x);
    }

    int pop() {
        int size = q.size();
        size--;
        while (size--) {
            q.push(q.front());
            q.pop();
        }
        int result = q.front();
        q.pop();
        return result;
    }

    int top() {
        return q.back();
    }

    bool empty() {
        return q.empty();
    }

private:
    queue<int> q;
};

