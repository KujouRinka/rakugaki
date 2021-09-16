struct node;
class Trie;

struct node {
public:
    node() : children(26), isEnd(false) {}
    vector<node *> children;
    bool isEnd;
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() : head(new node) {}

    /** Inserts a word into the trie. */
    void insert(const string &word) {
        struct node *thisNode = head;
        for (char ch : word) {
            int index = getInd(ch);
            if (thisNode->children[index] == nullptr)
                thisNode->children[index] = new node;
            thisNode = thisNode->children[index];
        }
        thisNode->isEnd = true;
    }

    /** Returns if the word is in the trie. */
    bool search(const string &word) {
        struct node *thisNode = head;
        for (char ch : word) {
            int index = getInd(ch);
            if (thisNode->children[index] == nullptr)
                return false;
            thisNode = thisNode->children[index];
        }
        return thisNode->isEnd;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(const string &prefix) {
        struct node *thisNode = head;
        for (char ch : prefix) {
            int index = getInd(ch);
            if (thisNode->children[index] == nullptr)
                return false;
            thisNode = thisNode->children[index];
        }
        return true;
    }

private:
    struct node *head;
    static inline int getInd(char ch) {
        return ch - 'a';
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
 