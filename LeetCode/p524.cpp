class Solution {
public:
    string findLongestWord(const string &s, const vector<string> &dictionary) {
        int maxLen = 0;
        int maxInd = -1;
        auto sz = dictionary.size();
        auto szRaw = s.size();
        for (int i = 0; i < sz; ++i) {
            int pRaw = 0, pVar = 0;
            const string &sr = dictionary[i];
            string::size_type szVar;
            if ((szVar = sr.size()) > maxLen ||(szVar == maxLen && (maxInd == -1 || sr < dictionary[maxInd]))) {
                while (pRaw != szRaw && pVar != szVar) {
                    if (sr[pVar] == s[pRaw])
                        ++pVar;
                    ++pRaw;
                }

                if (pVar == szVar) {
                    maxLen = szVar;
                    maxInd = i;
                }
            }
        }
        return maxInd == -1 ? "" : dictionary[maxInd];
    }
};
