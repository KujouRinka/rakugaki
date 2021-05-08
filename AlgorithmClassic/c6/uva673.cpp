#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool judge(const string &raw) {
    stack<char> s;

    for (const auto &ch : raw) {
        if (ch == '(' || ch == '[')
            s.push(ch);
        else {
            if (s.empty() || !((s.top() == '(' && ch == ')') || (s.top() == '[' && ch == ']')))
                return false;
            else
                s.pop();
        }
    }

    return s.empty();
}

int main() {
    freopen("read.in", "r", stdin);
    freopen("write.out", "w", stdout);

    int n;
    string discard;
    cin >> n;
    getline(cin, discard);
    while (n--) {
        string raw;
        getline(cin, raw);

        cout << (judge(raw) ? "Yes" : "No") << endl;
    }
    return 0;
}
