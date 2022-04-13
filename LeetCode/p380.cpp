class RandomizedSet {
public:
    RandomizedSet() {
        srand((unsigned)time(NULL));
    }
    
    bool insert(int val) {
        if (_find_map.count(val))
            return false;
        _find_map[val] = _idx_vec.size();
        _idx_vec.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if (_find_map.count(val) == 0)
            return false;
        _idx_vec[_find_map[val]] = _idx_vec.back();
        _find_map[_idx_vec.back()] = _find_map[val];
        _idx_vec.pop_back();
        _find_map.erase(val);
        return true;
    }
    
    int getRandom() {
        return _idx_vec[rand() % _idx_vec.size()];
    }

private:
    vector<int> _idx_vec;
    unordered_map<int, int> _find_map;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

