class TripleInOne {
public:
    TripleInOne(int stackSize)
            : m_st(stackSize * 3), m_max_sz(stackSize) {
        m_sz[0] = m_sz[1] = m_sz[2] = 0;
    }

    void push(int stackNum, int value) {
        if (m_sz[stackNum] < m_max_sz) {
            m_st[m_sz[stackNum] * 3 + stackNum] = value;
            ++m_sz[stackNum];
        }
    }

    int pop(int stackNum) {
        if (!isEmpty(stackNum)) {
            --m_sz[stackNum];
            return m_st[m_sz[stackNum] * 3 + stackNum];
        }
        return -1;
    }

    int peek(int stackNum) {
        if (!isEmpty(stackNum))
            return m_st[(m_sz[stackNum] - 1) * 3 + stackNum];
        return -1;
    }

    bool isEmpty(int stackNum) {
        return m_sz[stackNum] == 0;
    }

private:
    vector<int> m_st;
    int m_sz[3];
    int m_max_sz;
};
