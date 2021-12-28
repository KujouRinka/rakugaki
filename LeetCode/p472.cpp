class Trie {
public:
    Trie() : head(new Node) {};
    ~Trie() {
        deleteAll(head);
    }

    void insert(const string &s) {
        Node *this_node = this->head;
        for (char ch: s) {
            if (this_node->children[toInt(ch)] == nullptr)
                this_node->children[toInt(ch)] = new Node();
            this_node = this_node->children[toInt(ch)];
        }
        this_node->is_word = true;
    }

    bool catSearch(const string &s) {
        return _catSearch(s, 0, head);
    }

private:
    struct Node {
        Node() : is_word(false), children(26) {}
        bool is_word;
        vector<Node *> children;
    };

    Node *head;
    bool _catSearch(const string &s, int idx, Node *start) {
        for (; idx < s.size(); ++idx) {
            char ch = s[idx];
            int next_idx = toInt(ch);
            start = start->children[next_idx];
            if (start == nullptr) {
                return false;
            } else if (start->is_word) {
                if (_catSearch(s, idx + 1, head))
                    return true;
            }
        }
        if (start->is_word)
            return true;
        return false;
    }

    void deleteAll(Node *root) {
        if (root == nullptr)
            return;
        for (Node *n: root->children)
            deleteAll(n);
        delete root;
    }

    static inline int toInt(char ch) {
        return ch - 'a';
    }
};

class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string> &words) {
        Trie trie_tree;
        sort(words.begin(), words.end(), [](const string &lhs, const string &rhs) -> bool {
            return lhs.size() < rhs.size();
        });

        vector<string> result;
        result.reserve(words.size() / 5);
        for (const string &s: words) {
            if (!trie_tree.catSearch(s))
                trie_tree.insert(s);
            else
                result.emplace_back(s);
        }
        return result;
    }
};

