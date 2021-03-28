//
// Created by KujouRinka on 2021/1/31.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdint>
#include "run_all.h"

void Score() {
    int ch, tot = 0;
    while ((ch = getchar()) != EOF)
        if (ch == '1')
            tot++;
    printf("%d", tot);
}

void MolarMass(char *Molar) {
    float Mass = 0.0, AtomMassP = 0;

    while (*Molar != '\0') {
        switch (*Molar++)   /* get atom mass */
        {
            case 'C':
                AtomMassP = 12.01;
                break;
            case 'H':
                AtomMassP = 1.008;
                break;
            case 'O':
                AtomMassP = 16.00;
                break;
            case 'N':
                AtomMassP = 14.01;
                break;
        }

        int ThisFac = 0;
        while (isdigit(*Molar)) {
            ThisFac *= 10;
            ThisFac += (int) (*Molar - 48);
            Molar++;
        }

        Mass += AtomMassP * (ThisFac ? ThisFac : 1);
    }
    printf("%.3f\n", Mass);
}

void DigitCounting(int Range) {
    int Statis[10] = {0};
    for (int i = 0; i <= Range; i++) {
        int Tmpi = i;
        while (Tmpi > 0) {
            Statis[Tmpi % 10]++;
            Tmpi /= 10;
        }
    }
    for (int i = 0; i < 10; i++)
        printf("%d ", Statis[i]);
    printf("\n");
}

void PeriodicStrings(char *Str) {
    int Len = strlen(Str);

    for (int Cir = 1; Cir <= Len; Cir++) {
        if (Len % Cir == 0) {
            int i = Cir;
            for (; i < Len; i++) {
                if (Str[i % Cir] != Str[i])
                    break;
            }
            if (i == Len) {
                printf("%d\n", Cir);
                break;
            }
        }
    }
}

int DNAHamming(char *DNA1, char *DNA2) {
    int Hamming = 0;

    while (*DNA1 != '\0')
        if (*DNA1++ != *DNA2++)
            Hamming++;

    return Hamming;
}

void DNAConString(char (*DNAs)[1001], int Strs) {
    int Hammings[100] = {0};
    for (int i = 0; i < Strs; i++) {
        for (int j = i + 1; j < Strs; j++) {
            int Hamming = DNAHamming(DNAs[i], DNAs[j]);
            Hammings[i] += Hamming;
            Hammings[j] += Hamming;
        }
    }

    int MinHamming = 1000;
    int MinIndex = 0;
    for (int i = 0; i < Strs; i++)
        if (Hammings[i] < MinHamming) {
            MinHamming = Hammings[i];
            MinIndex = i;
        }

    char *MinHammingStr = DNAs[MinIndex];
    for (int i = MinIndex + 1; i < Strs; i++) {
        if (Hammings[i] == MinHamming) {
            if (strcmp(MinHammingStr, DNAs[i]) > 0)
                MinHammingStr = DNAs[i];
        }
    }

    printf("%s\n", MinHammingStr);
}

