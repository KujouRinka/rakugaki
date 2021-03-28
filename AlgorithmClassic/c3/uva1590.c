//
// Created by KujouRinka on 2021/3/28.
//

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

// uva1590
uint32_t IPConvert(char *IP) {
    uint32_t IPBinary = 0;
    uint8_t SegNum = 0;
    while (1) {
        if (*IP == '.' || *IP == '\0') {
            IPBinary <<= 8;
            IPBinary |= SegNum;
            SegNum = 0;
            if (*IP == '\0')
                break;
        } else {
            SegNum *= 10;
            SegNum += (uint8_t) (*IP - 48);
        }
        IP++;
    }
    return IPBinary;
}

void UnpackBin(int *IP, uint32_t IPBin) {
    uint32_t Getter = (uint32_t) UINT8_MAX;
    for (int i = 3; i >= 0; i--)
        IP[3 - i] = ((IPBin >> i * 8) & Getter);
}

int GetHostNum(char (*IPs)[16], int IPNums) {
    uint32_t *RawIP = (uint32_t *) calloc(IPNums, sizeof(uint32_t));
    uint32_t CIP;
    for (int i = 0; i < IPNums; i++)
        RawIP[i] = IPConvert(IPs[i]);
    for (int i = 0; i < IPNums; i++)
        CIP = RawIP[i];
    uint32_t BaseCase = RawIP[0];
    int Offset = 0;
    for (int i = 0; i < IPNums && Offset <= 32;) {
        if ((BaseCase >> Offset) ^ (RawIP[i] >> Offset))
            Offset++;
        else
            i++;
    }
    return Offset;
}

void IPNetwork(int (*Result)[4], char (*IPs)[16], int IPNums) {
    int HostNum = GetHostNum(IPs, IPNums);
    uint32_t MaskBin, MinIPBin;
    MinIPBin = IPConvert(IPs[0]);
    MaskBin = ~(((uint32_t) 1 << HostNum) - 1);
    MinIPBin = MinIPBin & MaskBin;

    UnpackBin(Result[0], MinIPBin);
    UnpackBin(Result[1], MaskBin);
}
