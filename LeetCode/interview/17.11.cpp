class Solution {
public:
    int findClosest(vector<string> &words, const string &word1, const string &word2) {
        int p1 = -1, p2 = -1;
        int dist = words.size();
        for (int i = 0; i < words.size(); ++i) {
            if (word1 == words[i])
                p1 = i;
            else if (word2 == words[i])
                p2 = i;
            if (p1 != -1 && p2 != -1)
                dist = min(dist, abs(p2 - p1));
        }
        return dist;
    }
};

