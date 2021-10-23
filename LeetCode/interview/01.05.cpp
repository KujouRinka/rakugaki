class Solution {
public:
    bool oneEditAway(string &first, string &second) {
        int sz_first = first.size(), sz_second = second.size();
        if (abs(sz_first - sz_second) > 1)
            return false;
        bool has_chance = true;
        if (sz_first == sz_second) {
            auto it_first = first.begin(), it_second = second.begin();
            while (it_first != first.end()) {
                if (*it_first++ != *it_second++) {
                    if (!has_chance)
                        return false;
                    has_chance = false;
                }
            }
            return true;
        } else {
            string::iterator it_big, it_small, it_end;
            if (sz_first > sz_second) {
                it_big = first.begin();
                it_small = second.begin();
                it_end = first.end();
            } else {
                it_big = second.begin();
                it_small = first.begin();
                it_end = second.end();
            }
            while (it_big != it_end) {
                if (*it_big != *it_small) {
                    if (!has_chance)
                        return false;
                    has_chance = false;
                    ++it_big;
                    continue;
                }
                ++it_big;
                ++it_small;
            }
            return true;
        }
    }
};
