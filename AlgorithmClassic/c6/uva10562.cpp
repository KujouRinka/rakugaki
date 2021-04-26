#include <iostream>
#include <string>
#include <vector>

using namespace std;

void makeTree(vector<string> &data, int posX, int posY) {
    cout << data[posX][posY];
    cout << "(";
    if (posY < data[posX + 1].size() && data[posX + 1][posY] == '|') {
        int boundX = posX + 2;
        int boundYLower, boundYUpper;
        boundYLower = boundYUpper = posY;
        while (--boundYLower >= 0 && data[boundX][boundYLower] == '-');
        ++boundYLower;
        while (++boundYUpper != data[boundX].size() && data[boundX][boundYUpper] == '-');
        for (int i = boundYLower; i < boundYUpper && i < data[boundX + 1].size(); ++i) {
            if (data[boundX + 1][i] != ' ') {
                makeTree(data, boundX + 1, i);
            }
        }

    }
    cout << ")";
}

int main() {
    int treeNum;
    cin >> treeNum;
    string discard;
    getline(cin, discard);
    while (treeNum--) {
        vector<string> data;
        string eachLine;

        // read data
        while (getline(cin, eachLine) && eachLine != "#") {
            data.push_back(eachLine);
        }
        data.emplace_back(202, ' ');
        cout << "(";
        if (data.size() > 1)
            for (int i = 0; i < data[0].size(); ++i) {
                if (data[0][i] != ' ') {
                    makeTree(data, 0, i);
                }
            }
        cout << ")";
        cout << endl;
    }
    return 0;
}
