//
// Created by KujouRinka on 2021/3/28.
//

#include <iostream>
#include <cstring>

using namespace std;

// uva679
int DroppingBallsv1() {
    int leave[1 << 20] = {0};
    int n;
    int depth, ballNum;
    cin >> n;
    while (n--) {
        cin >> depth >> ballNum;
        memset(leave, 0, sizeof(leave));
        int current;
        while (ballNum--) {
            int step = 1;
            current = 1;
            while (step != depth) {
                leave[current] = !leave[current];
                if (leave[current])
                    current *= 2;
                else
                    current = current * 2 + 1;
                ++step;
            }
        }
        cout << current << endl;
    }
    return 0;
}

