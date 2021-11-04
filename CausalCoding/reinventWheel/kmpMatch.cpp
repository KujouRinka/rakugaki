#include <vector>
#include <string>
#include <cstring>

using namespace std;

vector<int> strNext(const string &s) {

    // calculate next_vec
    auto sz = s.size();
    if (sz == 0)
        return {};
    vector<int> next_vec(sz);
    next_vec[0] = -1;
    for (int j = 1; j < sz; ++j) {
        for (int k = j - 1; k >= 1; --k) {
            if (strncmp(s.c_str(), s.c_str() + (j - k), k) == 0) {
                next_vec[j] = k;
                break;
            }
        }
    }

    // calculate next_val_vec
    vector<int> next_val_vec(sz);
    next_val_vec[0] = -1;
    for (int i = 0; i < sz; ++i) {
        if (s[i] == s[next_vec[i]])
            next_val_vec[i] = next_val_vec[next_vec[i]];
        else    // s[i] != s[next_vec[i]]
            next_val_vec[i] = next_vec[i];
    }
    return next_val_vec;
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
