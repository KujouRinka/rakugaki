class Trie {
public:
    Trie() : head(make_shared<Node>()) {};

    void insert(const string &s) {
        shared_ptr<Node> this_ptr = head;
        for (char ch: s) {
            int next = toInt(ch);
            if (this_ptr->children[next] == nullptr)
                this_ptr->children[next] = make_shared<Node>();
            this_ptr = this_ptr->children[next];
        }
        this_ptr->is_word = true;
    }

    bool specFind(const string &s) {
        shared_ptr<Node> this_ptr = head;
        for (char ch: s) {
            int next = toInt(ch);
            if (this_ptr->children[next] == nullptr)
                return false;
            this_ptr = this_ptr->children[next];
            if (!this_ptr->is_word)
                return false;
        }
        return true;
    }

private:
    struct Node {
        Node() : is_word(false), children() {}
        array<shared_ptr<Node>, 26> children;
        bool is_word;
    };

    shared_ptr<Node> head;

    static inline int toInt(char ch) {
        return ch - 'a';
    }
};

class Solution {
public:
    string longestWord(const vector<string> &words) {
        Trie t;
        for (auto &s: words)
            t.insert(s);
        string max_str;
        for (auto &s: words) {
            if (t.specFind(s) &&
                (s.size() > max_str.size() || (s.size() == max_str.size() && s < max_str)))
                max_str = s;
        }
        return max_str;
    }
};

