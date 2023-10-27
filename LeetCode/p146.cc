class LRUCache {
  typedef int key_type;
  typedef pair<const key_type, int> value_type;
 public:
  LRUCache(int capacity)
      : cap(capacity) {
    key_to_val.reserve(capacity);
  }

  int get(int key) {
    if (!key_to_val.contains(key)) {
      return -1;
    }
    auto it = key_to_val[key];
    lst.splice(lst.begin(), lst, it);
    return lst.begin()->second;
  }

  void put(int key, int value) {
    if (key_to_val.contains(key)) {
      key_to_val[key]->second = value;
      auto it = key_to_val[key];
      lst.splice(lst.begin(), lst, it);
    } else {
      if (lst.size() == cap) {
        key_to_val.erase(lst.back().first);
        lst.pop_back();
      }
      lst.emplace_front(key, value);
      key_to_val.insert({key, lst.begin()});
    }
  }

 private:
  const int cap;
  list<value_type> lst;
  unordered_map<key_type, list<value_type>::iterator> key_to_val;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

