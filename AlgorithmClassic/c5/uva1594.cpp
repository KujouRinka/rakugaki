//
// Created by KujouRinka on 2021/3/28.
//

#include <iostream>

using namespace std;
// uva1594
int DucciSeq() {
    int n;
    cin >> n;
    while (n--) {
        int TupleSize, ZeroCounter = 0;
        int Tuple[15] = {0};
        cin >> TupleSize;
        for (int i = 0; i < TupleSize; i++) {
            cin >> Tuple[i];
            if (!Tuple[i])
                ZeroCounter++;
        }

        int NextIndex;
        int LoopCounter = 0;
        int TmpTuple[15] = {0};
        for (int i = 0;; i = NextIndex) {
            if (i == 0) {
                memcpy(TmpTuple, Tuple, sizeof(int) * TupleSize);
                LoopCounter++;
            }
            if (LoopCounter == 1001) {
                cout << "LOOP" << endl;
                break;
            }
            if (ZeroCounter == TupleSize) {
                cout << "ZERO" << endl;
                break;
            }
            NextIndex = (i + 1) % TupleSize;
            Tuple[i] = abs(TmpTuple[i] - TmpTuple[NextIndex]);
            if (TmpTuple[i] == 0 && Tuple[i])
                ZeroCounter--;
            else if (TmpTuple[i] && Tuple[i] == 0)
                ZeroCounter++;
        }
    }
    return 0;
}
