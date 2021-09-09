class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;

        auto beginIt = words.begin(), endIt = words.begin();
        while (beginIt != words.end()) {
            // 统计单词范围
            int stringLen = (*endIt).size();
            int thisLen = (*endIt++).size();
            for (; endIt != words.end(); ++endIt) {
                thisLen += (*endIt).size() + 1;
                if (thisLen > maxWidth)
                    break;
                stringLen += (*endIt).size();
            }

            string s;
            int sep;
            // 最后一行
            if (endIt == words.end()) {
                s = join(beginIt, endIt, " ");
                s += blank(maxWidth - s.size());
            } else {
                int wordsNum = endIt - beginIt;
                int sepNum = maxWidth - stringLen;
                // 该行只有一个单词
                if (wordsNum == 1) {
                    s = *beginIt;
                    s += blank(maxWidth - s.size());
                } else if ((sep = sepNum % (wordsNum - 1)) == 0) {  // 能平均分配空格
                    s = join(beginIt, endIt, blank(sepNum / (wordsNum - 1)));
                } else {    // 不能平均分配空格
                    int baseSep = sepNum / (wordsNum - 1);
                    string b2 = blank(baseSep + 1);
                    while (sep--)
                        s += *beginIt++ + b2;
                    s += join(beginIt, endIt, blank(baseSep));
                }
            }
            result.push_back(s);
            beginIt = endIt;
        }
        return result;
    }

private:
    static string blank(int n) {
        return string(n, ' ');
    }

    template<typename T>static string join(T it1, T it2, string sep) {
        string s(*it1);
        for (++it1; it1 != it2; ++it1)
            s += sep + *it1;
        return s;
    }
};
