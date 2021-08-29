#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

template<typename T>
T det(const vector<vector<T>> &m) {
    if (m.size() != m[0].size()) {
        throw runtime_error("invalid dimension");
    }
    if (m.size() == 1)
        return m[0][0];
    else {
        T res = 0;
        for (int i = 0; i != m.size(); ++i) {
            vector<vector<int>> nm;
            T fac = m[i][0];
            for (int j = 0; j != m.size(); ++j) {
                if (i != j)
                    nm.emplace_back(m[j].begin() + 1, m[j].end());
            }
            T A = pow(-1, i) * det(nm);
            res += fac * A;
        }
        return res;
    }
}

int main() {
    vector<int> v1 = {1, 2, 3, 4};
    vector<int> v2 = {4, 7, 6, 5};
    vector<int> v3 = {7, 8, 9, 9};
    vector<int> v4 = {8, 8, 4, 6};
    vector<vector<int>> m = {v1, v2, v3, v4};
    cout << det(m);
    return 0;
}
