//
// Created by KujouRinka on 2021/3/28.
//

#include <stdio.h>
#include <stdlib.h>

// uva12108
int IsIntoSleep(int StudentPtr, int *Student) {
    int CirCount = StudentPtr + 1;
    return CirCount == Student[0];
}

int IsToWake(int StudentPtr, int *Student) {
    int CirCount = StudentPtr + 1;
    return CirCount == Student[0] + Student[1];
}

int IsAllowToSleep(int Nums, int StudentInSleep) {
    int Awake = Nums - StudentInSleep;
    return StudentInSleep > Awake;
}

void ExTiredStus(int (*Students)[3], int Nums) {
    int *StudentStats = (int *) malloc(sizeof(int) * Nums);
    int *StudentPtr = (int *) malloc(sizeof(int) * Nums);
    int *StudentSleepDelay = (int *) calloc(Nums, sizeof(int));

    int StudentInSleep = 0;
    int Mins = 1;

    // init the first minute
    for (int i = 0; i < Nums; i++) {
        StudentPtr[i] = (Students[i][2] - 1) % (Students[i][0] + Students[i][1]);
        StudentStats[i] = Students[i][0] >= (StudentPtr[i] + 1) ? 1 : 0;
        if (!StudentStats[i])
            StudentInSleep++;
    }

    while (StudentInSleep) {
        for (int i = 0; i < Nums; i++) {
            if (StudentSleepDelay[i]) {
                StudentSleepDelay[i]--;
            } else if (IsIntoSleep(StudentPtr[i], Students[i])) {   // is going to sleep
                if (IsAllowToSleep(Nums, StudentInSleep)) { // allow to sleep
                    StudentStats[i] = 0;
                    StudentPtr[i]++;
                } else    // do not allow to sleep
                    StudentSleepDelay[i] = Students[i][0];
            } else if (IsToWake(StudentPtr[i], Students[i])) {    // is going to wake
                StudentStats[i] = 1;
                StudentPtr[i] = 0;
            } else {  // continue doing
                StudentPtr[i]++;
            }
        }

        StudentInSleep = 0;
        for (int i = 0; i < Nums; i++)
            if (StudentStats[i] == 0)
                StudentInSleep++;

        Mins++;
        if (Mins == 1000) {
            printf("-1\n");
            return;
        }
    }
    printf("%d\n", Mins);
}
