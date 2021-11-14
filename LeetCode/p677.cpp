struct TrieTree {
    TrieTree() : val(0) {
        memset(next, 0, sizeof(next));
    }
    int val;
    TrieTree *next[26];
};

class MapSum {
public:
    MapSum() : tree_head(new TrieTree) {}
    ~MapSum() {
        deleteNode(tree_head);
    }

    void insert(const string &key, int val) {
        auto head = tree_head;
        for (char ch: key) {
            if (head->next[getInd(ch)] == nullptr)
                head->next[getInd(ch)] = new TrieTree;
            head = head->next[getInd(ch)];
        }
        head->val = val;
    }

    int sum(const string &prefix) {
        auto head = tree_head;
        for (char ch: prefix) {
            if ((head = head->next[getInd(ch)]) == nullptr)
                return 0;
        }
        return dfs(head);
    }

private:
    TrieTree *tree_head;

    static int dfs(TrieTree *head) {
        if (head == nullptr)
            return 0;
        int sum = 0;
        for (auto i: head->next)
            sum += dfs(i);
        return head->val + sum;
    }

    static void deleteNode(TrieTree *head) {
        if (head == nullptr)
            return;
        for (auto i: head->next)
            deleteNode(i);
        delete head;
    }

    inline static int getInd(char ch) {
        return ch - 'a';
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
