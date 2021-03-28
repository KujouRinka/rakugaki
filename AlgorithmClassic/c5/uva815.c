//
// Created by KujouRinka on 2021/3/28.
//

#include <stdio.h>

// uva815
int CalFloodedBlocks(int (*Square)[30], int *SquareInfo, int WaterAltitude) {
    int Flooded = 0;
    for (int i = 0; i < SquareInfo[0]; i++)
        for (int j = 0; j < SquareInfo[1]; j++)
            if (WaterAltitude > Square[i][j])
                Flooded++;
    return Flooded;
}

float CalDeltaHeight(int FloodedBlocks, int NextWaterConsume) {
    return (float) NextWaterConsume / (FloodedBlocks * 100);
}

void Flooded(int (*Square)[30], int *SquareInfo, int WaterVolume) {
    int WaterAltitude = -1000;  // Min block height
    int LeaveWaterVolume = WaterVolume;
    int FloodedBlocks;
    int NextWaterConsume;
    float DeltaHeight;
    float WaterFinalHeight;
    float UnderRegionRat;
    while (LeaveWaterVolume) {
        FloodedBlocks = CalFloodedBlocks(Square, SquareInfo, WaterAltitude + 1);
        NextWaterConsume = FloodedBlocks * 100;
        if (LeaveWaterVolume - NextWaterConsume <= 0) {
            NextWaterConsume = LeaveWaterVolume;
            DeltaHeight = CalDeltaHeight(FloodedBlocks, NextWaterConsume);
            WaterFinalHeight = WaterAltitude + DeltaHeight;
            LeaveWaterVolume = 0;
        } else {
            WaterAltitude++;
            LeaveWaterVolume -= NextWaterConsume;
        }
    }
    UnderRegionRat = (float) FloodedBlocks / (SquareInfo[0] * SquareInfo[1]);

    printf("Water level is %.2f meters.\n", WaterFinalHeight);
    printf("%.2f percent of the region is under water.\n\n", UnderRegionRat * 100);
}
