//
// Created by KujouRinka on 2021/3/28.
//

#include <stdio.h>

// uva 10340
void AllInAll(char *s, char *t) {
    while (*s != '\0' && *t != '\0') {
        if (*s == *t)
            s++;
        *t++;
    }
    if (*s == '\0')
        printf("Yes\n");
    else
        printf("No\n");
}
