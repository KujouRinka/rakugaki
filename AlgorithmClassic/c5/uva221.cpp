//
// Created by KujouRinka on 2021/3/28.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// uva221
namespace uva221 {
    struct Building {
        int ID;
        int x, y, xlen, h;
        bool Visible;

        Building(int ID, int x, int y, int xlen, int h, bool Visible = false) {
            this->ID = ID;
            this->x = x;
            this->y = y;
            this->xlen = xlen;
            this->h = h;
            this->Visible = Visible;
        }

        bool operator<(const Building &rhs) const {
            return x < rhs.x || (x == rhs.x && y < rhs.y);
        }
    };

    bool Covered(Building B, float GapPoint) {
        return B.x <= GapPoint && B.x + B.xlen >= GapPoint;
    }

    bool IsVisible(Building B, vector<Building> &Bs, float GapPoint) {
        if (!Covered(B, GapPoint))
            return false;
        for (auto &i : Bs) {
            if (i.y < B.y && i.h >= B.h && Covered(i, GapPoint))
                return false;
        }
        return true;
    }

    int UrbanElevations() {
        int n, Count = 0;

        vector<Building> Buildings;
        int Gap[202];

        while (cin >> n && n) {
            int x, y, xlen, ylen, h;
            Buildings.clear();
            for (int i = 0; i < n; i++) {
                cin >> x >> y >> xlen >> ylen >> h;
                Building TmpBuilding(i + 1, x, y, xlen, h);
                Gap[i * 2] = x;
                Gap[i * 2 + 1] = x + xlen;
                Buildings.push_back(TmpBuilding);
            }

            sort(Buildings.begin(), Buildings.end());
            sort(Gap, Gap + n * 2);
            int s = unique(Gap, Gap + n * 2) - Gap;

            for (int i = 0; i < Buildings.size(); i++) {
                for (int j = 0; j < s - 1; j++)
                    if (IsVisible(Buildings[i], Buildings, (Gap[j] + Gap[j + 1]) / 2.0)) {
                        Buildings[i].Visible = true;
                        break;
                    }
            }
            if (Count)
                cout << "\n";
            cout << "For map #" << ++Count << ", the visible buildings are numbered as follows:" << endl;
            for (auto &Building : Buildings) {
                if (Building.Visible)
                    cout << Building.ID << " ";
            }
            cout << "\n";
        }

        return 0;
    }
}
