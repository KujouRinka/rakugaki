class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> _translated_set;
        for (auto &s: words)
            _translated_set.insert(trans(s));
        return _translated_set.size();
    }

private:
    static const char *char_map[26];

    inline string trans(string &word) {
        string s;
        for (char ch: word)
            s.append(char_map[ch - 'a']);
        return s;
    }
};

const char *Solution::char_map[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

