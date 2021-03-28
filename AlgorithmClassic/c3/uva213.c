//
// Created by KujouRinka on 2021/3/28.
//

#include <stdio.h>

// uva213
void MsgDecode(char *Msg, char *Header) {
    char Table[8][(1 << 8) - 1] = {0};
    for (int i = 0; i < 8; i++) {
        int Upper = (1 << (i + 1)) - 1;
        for (int j = 0; j < Upper; j++) {
            Table[i][j] = *Msg++;
            if (*Msg == '\0')
                goto EndInit;
        }
    }
    EndInit:;

    char CodeLen[3] = {0};
    int Len = 0;
    int Index = 0;
    while (*Header != '\0') {
        Len = 0;
        for (int i = 0; i < 3; i++)
            Len += ((int) (*Header++ - 48) << (2 - i));
        if (Len == 0)
            break;
        while (1) {
            Index = 0;
            for (int i = Len; i >= 1; i--)
                Index += ((int) (*Header++ - 48) << (i - 1));
            if (Table[Len - 1][Index])
                printf("%c", Table[Len - 1][Index]);
            else
                break;
        }
    }
}
