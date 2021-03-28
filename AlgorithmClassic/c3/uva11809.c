//
// Created by KujouRinka on 2021/3/28.
//

#include <stdio.h>
#include <string.h>

//uva 11809
void FloatNumber(char *SciNum) {
    int AUpper = 0, BLower = 0, BUpper = 0;
    int DocIndex = 0, Power = 0;
    char SciTmpIndex = 0;
    while (SciNum[++SciTmpIndex] != 'e');
    DocIndex = 1;

    AUpper = SciTmpIndex;
    BLower = AUpper + 1;
    BUpper = strlen(SciNum);
    sscanf(SciNum + BLower, "%d", &Power);

    printf("%d ", AUpper);
    printf("%d ", DocIndex);
    printf("%d\n", Power);
}
