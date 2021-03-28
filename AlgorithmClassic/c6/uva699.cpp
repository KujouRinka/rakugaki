//
// Created by KujouRinka on 2021/3/28.
//

#include <iostream>
#include <sstream>
#include <map>

using namespace std;

// uva699
namespace uva699 {
    map<int, int> rowSum;
    int CASE = 0;

    void makeTree(int offset, stringstream &ss) {
        int leftNodeValue, rightNodeValue;

        ss >> leftNodeValue;
        if (leftNodeValue != -1) {
            rowSum[offset - 1] += leftNodeValue;
            makeTree(offset - 1, ss);
        }

        ss >> rightNodeValue;
        if (rightNodeValue != -1) {
            rowSum[offset + 1] += rightNodeValue;
            makeTree(offset + 1, ss);
        }
    }

    int fallingLeaves() {
        int firstNodeValue;
        while (true) {
            rowSum.clear();
            string buffer;
            getline(cin, buffer);
            stringstream ss(buffer);

            ss >> firstNodeValue;
            if (firstNodeValue == -1)
                break;
            rowSum[0] += firstNodeValue;
            ss.clear();
            makeTree(0, ss);

            cout << "Case " << ++CASE << ":" << endl;
            for (auto it = rowSum.cbegin(); it != rowSum.end(); ++it) {
                if (it == rowSum.cbegin())
                    cout << it->second;
                else
                    cout << " " << it->second;
            }
            cout << endl << endl;
        }
        return 0;
    }
}
