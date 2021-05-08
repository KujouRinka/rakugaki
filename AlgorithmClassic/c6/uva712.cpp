#include <iostream>
#include <string>

using namespace std;

char res(const string &raw, const string &path) {
    for (const auto &i : path) {
        if (i == '0')
            return res(raw.substr(0, raw.size() / 2), path.substr(1));
        else
            return res(raw.substr(raw.size() / 2), path.substr(1));
    }
    return raw[0];
}

int main() {
    freopen("read.in", "r", stdin);

    int n;
    int CASE = 0;
    while (cin >> n && n != 0) {
        string raw;
        string discard;
        getline(cin, discard);
        getline(cin, discard);
        getline(cin, raw);

        int dataGroup;
        cin >> dataGroup;

        cout << "S-Tree #" << ++CASE << ":" << endl;
        while (dataGroup--) {
            string path;
            cin >> path;
            cout << res(raw, path);
        }

        cout << endl << endl;
    }
    return 0;
}
