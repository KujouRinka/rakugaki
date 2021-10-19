struct node {
public:
    node() : end(false), next(26) {}
    ~node() {
        for (auto p: next)
            delete p;
    }
    bool end;
    vector<node *> next;
};

class WordDictionary {
public:
    WordDictionary() : m_head(new node) {
    }

    ~WordDictionary() {
        delete m_head;
    }

    void addWord(const string &word) {
        node *insert_p = m_head;
        for (char ch: word) {
            if (insert_p->next[ch - 'a'] == nullptr)
                insert_p->next[ch - 'a'] = new node;
            insert_p = insert_p->next[ch - 'a'];
        }
        insert_p->end = true;
    }

    bool search(const string &word) {
        return dfsFind(word, 0, m_head);
    }

private:
    node *m_head;

    bool dfsFind(const string &word, int start_ind, node *head) {
        auto sz = word.size();
        if (start_ind == sz)
            return head->end;
        if (word[start_ind] == '.') {
            for (int j = 0; j < 26; ++j)
                if (head->next[j] != nullptr && dfsFind(word, start_ind + 1, head->next[j]))
                    return true;
            return false;
        } else {
            node *next = head->next[word[start_ind] - 'a'];
            if (next == nullptr)
                return false;
            return dfsFind(word, start_ind + 1, next);
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
