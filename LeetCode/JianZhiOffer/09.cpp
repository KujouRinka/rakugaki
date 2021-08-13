class CQueue {
public:
    CQueue() = default;

    void appendTail(int value) {
        inS.push(value);
    }

    int deleteHead() {
        int tmp;
        if (outS.empty())
            transVal(outS, inS);
        if (outS.empty())
            tmp = -1;
        else {
            tmp = outS.top();
            outS.pop();
        }
        return tmp;
    }

    void transVal(stack<int> &dst, stack<int> &src) {
        while (!src.empty()) {
            dst.push(src.top());
            src.pop();
        }
    }

private:
    stack<int> inS;
    stack<int> outS;
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
 