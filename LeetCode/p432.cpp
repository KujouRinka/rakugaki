class AllOne {
public:
    AllOne() = default;

    void inc(string key) {
        if (_toL_map.count(key)) {
            auto this_it = _toL_map[key];
            int next_cnt = this_it->cnt + 1;
            if (this_it == _lst.begin() || prev(this_it)->cnt != next_cnt)
                _lst.insert(this_it, Holder(key, next_cnt));
            else
                prev(this_it)->str_set.insert(key);
            this_it->str_set.erase(key);
            _toL_map[key] = prev(this_it);
            if (this_it->str_set.empty())
                _lst.erase(this_it);
        } else {    // insert a new
            if (_lst.back().cnt == 1)
                _lst.back().str_set.insert(key);
            else
                _lst.emplace_back(Holder(key));
            _toL_map[key] = prev(_lst.end());
        }
    }

    void dec(const string &key) {
        auto this_it = _toL_map[key];
        int next_cnt = this_it->cnt - 1;
        if (next_cnt > 0) {
            if (next(this_it) == _lst.end() || next(this_it)->cnt != next_cnt)
                _lst.insert(next(this_it), Holder(key, next_cnt));
            else
                next(this_it)->str_set.insert(key);
            _toL_map[key] = next(this_it);
        } else {
            _toL_map.erase(key);
        }
        this_it->str_set.erase(key);
        if (this_it->str_set.empty())
            _lst.erase(this_it);
    }

    string getMaxKey() {
        return _lst.empty() ? "" : *(_lst.front().str_set.begin());
    }

    string getMinKey() {
        return _lst.empty() ? "" : *(_lst.back().str_set.begin());
    }

private:
    struct Holder {
        Holder(const string &s, int n_cnt = 1) : cnt(n_cnt) {
            str_set.insert(s);
        }
        int cnt;
        unordered_set<string> str_set;
    };

    unordered_map<string, list<Holder>::iterator> _toL_map;
    list<Holder> _lst;
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */

