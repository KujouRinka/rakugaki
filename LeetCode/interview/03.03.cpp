class StackOfPlates {
public:
    StackOfPlates(int cap) : _cap(cap) {}

    void push(int val) {
        if (_cap == 0)
            return;
        if (_st_lst.empty() || _st_lst.back().size() == _cap)
            _st_lst.emplace_back();
        _st_lst.back().push(val);
    }

    int pop() {
        if (_st_lst.empty())
            return -1;
        int ret = _st_lst.back().top();
        _st_lst.back().pop();
        if (_st_lst.back().empty())
            _st_lst.pop_back();
        return ret;
    }

    int popAt(int index) {
        if (index >= _st_lst.size())
            return -1;
        auto it = _st_lst.begin();
        while (index--)
            ++it;
        int ret = it->top();
        it->pop();
        if (it->empty())
            _st_lst.erase(it);
        return ret;
    }

private:
    int _cap;
    list<stack<int>> _st_lst;
};

/**
 * Your StackOfPlates object will be instantiated and called as such:
 * StackOfPlates* obj = new StackOfPlates(cap);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAt(index);
 */

