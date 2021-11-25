#include <vector>
#include <string>
#include <cstring>

using namespace std;

vector<int> strNext(const string &s) {
    int sz = s.size();
    if (sz == 0)
        return {};
    vector<int> next_vec(sz);
    next_vec[0] = -1;
    for (int j = 0, i = 1; i <= sz - 2;) {
        if (s[i] == s[j]) {
            next_vec[i + 1] = j + 1;
            ++i;
            ++j;
            if (s[i] == s[next_vec[i]])
                next_vec[i] = next_vec[next_vec[i]];
        } else if (j == 0) {
            ++i;
        } else {
            j = max(next_vec[j], 0);
        }
    }
    return next_vec;
}

int kmpMatch(const string &tar, const string &mode) {
    auto next2 = strNext(mode);
    int sz_tar = tar.size();
    int sz_src = mode.size();
    int p_tar = 0, p_src = 0;
    while (p_tar < sz_tar && p_src < sz_src) {
        if (tar[p_tar] == mode[p_src]) {
            ++p_tar;
            ++p_src;
        } else if (next2[p_src] != -1) {
            p_src = next2[p_src];
        } else {
            p_src = 0;
            ++p_tar;
        }
    }
    return p_src == sz_src ? p_tar - sz_src : -1;
}
