//
// Created by KujouRinka on 2021/3/28.
//

#include <stdio.h>
#include <string.h>

// uva1368
void DNAConStringRight(char (*DNAs)[1001], int Strs, int Len) {
    int AS[4] = {0};
    char ResDNA[1001] = {0};
    char DNAHash[4] = {'A', 'C', 'G', 'T'};
    int Hamming = 0;
    for (int chIndex = 0; chIndex < Len; chIndex++) {
        memset(AS, 0, sizeof(int) * 4);
        for (int StrIndex = 0; StrIndex < Strs; StrIndex++) {
            char This;
            This = DNAs[StrIndex][chIndex];
            switch (This) {
                case 'A':
                    AS[0]++;
                    break;
                case 'C':
                    AS[1]++;
                    break;
                case 'G':
                    AS[2]++;
                    break;
                case 'T':
                    AS[3]++;
                    break;
            }
        }
        int MaxIndex = 0;
        for (int i = 1; i < 4; i++) {
            if (AS[i] > AS[MaxIndex]) {
                MaxIndex = i;
            }
        }
        ResDNA[chIndex] = DNAHash[MaxIndex];
        Hamming += Strs - AS[MaxIndex];
    }
    printf("%s\n", ResDNA);
    printf("%d\n", Hamming);
}
