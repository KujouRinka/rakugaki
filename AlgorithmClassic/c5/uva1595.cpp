//
// Created by KujouRinka on 2021/3/28.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// uva1595
namespace uva1595 {
    struct Point {
        int x, y;

        Point(int x, int y) {
            this->x = x;
            this->y = y;
        }

        bool operator<(const Point &rhs) const {
            return x < rhs.x || (x == rhs.x && y < rhs.y);
        }
    };

    bool cmp(Point P1, Point P2) {
        return P1.x > P2.x || (P1.x == P2.x && P1.y < P2.y);
    }

    int Symmetry() {
        int n;
        cin >> n;
        while (n--) {
            int PointNum;
            cin >> PointNum;
            vector<Point> Points;
            while (PointNum--) {
                int x, y;
                cin >> x >> y;
                Points.emplace_back(x, y);
            }

            vector<Point> ReversedPoints(Points);
            sort(Points.begin(), Points.end());
            sort(ReversedPoints.begin(), ReversedPoints.end(), cmp);

            double TmpSym = (Points[0].x + ReversedPoints[0].x) / 2.0;
            double ThisSym;
            auto it = Points.begin();
            for (auto &j : ReversedPoints) {
                ThisSym = (it->x + j.x) / 2.0;
                if (ThisSym != TmpSym || it->y != j.y)
                    break;
                TmpSym = ThisSym;
                it++;
            }
            if (it == Points.end())
                cout << "YES" << endl;
            else
                cout << "NO" << endl;

        }
        return 0;
    }
}
