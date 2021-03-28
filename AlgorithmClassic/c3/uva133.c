//
// Created by KujouRinka on 2021/3/28.
//

#include <stdio.h>
#include <string.h>

//uva 133

int NextP(int *Array, int Len, int P, int Step) {
    int D = (Step > 0 ? 1 : -1);
    while (Step) {
        P = (P + Len + D) % Len;
        if (Array[P] != 0)
            Step -= D;
    }
    return P;
}

void DoleQueue() {
    int Array[10];
    memset(Array, 1, sizeof(int) * 10);
    int P1 = -1, P2 = 10;
    int Leave = 10;
    while (Leave) {
        P1 = NextP(Array, 10, P1, 4);
        P2 = NextP(Array, 10, P2, -3);
        Array[P1] = 0;
        Array[P2] = 0;

        if (P1 == P2) {
            Leave--;
            printf("%d, ", P1 + 1);
        } else {
            Leave -= 2;
            printf("%d %d, ", P1 + 1, P2 + 1);
        }
    }
}
