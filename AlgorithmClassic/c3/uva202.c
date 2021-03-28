//
// Created by KujouRinka on 2021/3/28.
//

#include <stdio.h>
#include <stdint.h>

// uva 202
int FindCir(int ModStore[], int Len) {
    int Upper = Len - 1;
    for (int i = 1; i < Upper; i++)
        if (ModStore[i] == ModStore[Upper])
            return i;
    return 0;
}

void RepeatDec(int m, int n) {
    int Pre = m / n, CirCount = 0;
    printf("%d/%d = ", m, n);
    printf("%d.", Pre);
    int Index = 1, Dec, Mod = m % n, CirStartIndex;
    int8_t CirStore[3003] = {0};
    int ModStore[3003] = {0};
    do {
        Mod *= 10;
        ModStore[Index] = Mod;
        Dec = Mod / n;
        CirStore[Index++] = (int8_t) Dec;
        Mod = Mod % n;
    } while ((!(CirStartIndex = FindCir(ModStore, Index))) && Mod);

    if (CirStartIndex) {
        for (int i = 1; i < CirStartIndex; i++)
            printf("%d", CirStore[i]);
        printf("(");
        for (int i = CirStartIndex; i < Index - 1; i++) {
            printf("%d", CirStore[i]);
            CirCount++;
        }
        printf(")\n");
    } else {
        for (int i = 1; i < Index; i++) {
            printf("%d", CirStore[i]);
        }
        printf("(0)\n");
        CirCount = 1;
    }
    printf("   %d = number of digits in repeating cycle\n\n", CirCount);
}
