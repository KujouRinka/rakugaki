//
// Created by KujouRinka on 2021/3/28.
//

#include <iostream>
#include <vector>

using namespace std;

// uva101
namespace uva101 {
        vector<int> Pile[30];
        int TotalBlock;

        void FindBlock(int BlockNum, int *BlockInfo) {
            for (int i = 0; i < TotalBlock; i++)
                for (int j = 0; j < Pile[i].size(); j++)
                    if (Pile[i][j] == BlockNum) {
                        BlockInfo[0] = i;
                        BlockInfo[1] = j;
                    }
        }

        void CleanBlock(int *PositionInfo) {
            for (int i = PositionInfo[1] + 1; i < Pile[PositionInfo[0]].size(); i++) {
                int BackBlock = Pile[PositionInfo[0]][i];
                Pile[BackBlock].push_back(BackBlock);
            }
            Pile[PositionInfo[0]].resize(PositionInfo[1] + 1);
        }

        void PileUp(int *Pa, int Pb) {
            for (int i = Pa[1]; i < Pile[Pa[0]].size(); i++)
                Pile[Pb].push_back(Pile[Pa[0]][i]);
            Pile[Pa[0]].resize(Pa[1]);
        }

        void PrintRes() {
            for (int i = 0; i < TotalBlock; i++) {
                printf("%d:", i);
                for (int j = 0; j < Pile[i].size(); j++)
                    printf(" %d", Pile[i][j]);
                printf("\n");
            }
        }

        int BlocksProb(void) {
            string cmd1, cmd2;
            int a, b;

            cin >> TotalBlock;
            for (int i = 0; i < TotalBlock; i++)
                Pile[i].push_back(i);
            while (cin >> cmd1 >> a >> cmd2 >> b) {
                int Pa[2], Pb[2];
                FindBlock(a, Pa);
                FindBlock(b, Pb);
                if (Pa[0] == Pb[0])
                    continue;
                if (cmd1 == "move")
                    CleanBlock(Pa);
                if (cmd2 == "onto")
                    CleanBlock(Pb);
                PileUp(Pa, Pb[0]);
            }

            PrintRes();
            return 0;
        }
}
