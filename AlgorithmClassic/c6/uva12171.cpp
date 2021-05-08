#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cstring>

using namespace std;

vector<int> X, Y, Z;
int floodArray[102][102][102];
int dirX[] = {-1, 1, 0, 0, 0, 0, 0}, dirY[] = {0, 0, -1, 1, 0, 0}, dirZ[] = {0, 0, 0, 0, -1, 1};
int volume;
int s;

class block {
public:
    int x0, xe, y0, ye, z0, ze;

    block() = default;
} blocks[50];

void dfs(int x, int y, int z) {
    floodArray[x][y][z] = -1;
    volume -= X[x] * Y[y] * Z[z];
    for (int i = 0; i < 6; ++i) {
        int ix = x + dirX[i], iy = y + dirY[i], iz = z + dirZ[i];
        if (ix >= 0 && ix < X.size() && iy >= 0 && iy < Y.size() && iz >= 0 && iz < Z.size()) {
            if (floodArray[ix][iy][iz] == 1) {
                if (dirX[i]) s += Y[y] * Z[z];
                else if (dirY[i]) s += X[x] * Z[z];
                else s += X[x] * Y[y];  // surface
            } else if (floodArray[ix][iy][iz] == 0)
                dfs(ix, iy, iz);
        }
    }
}

void draw(int blockNum) {
    for (int i = 0; i < blockNum; ++i) {
        int startX = upper_bound(X.begin(), X.end(), blocks[i].x0) - X.begin();
        int startY = upper_bound(Y.begin(), Y.end(), blocks[i].y0) - Y.begin();
        int startZ = upper_bound(Z.begin(), Z.end(), blocks[i].z0) - Z.begin();

        // fill
        for (int ix = startX; ix < X.size() && X[ix] <= blocks[i].xe; ++ix)
            for (int iy = startY; iy < Y.size() && Y[iy] <= blocks[i].ye; ++iy)
                for (int iz = startZ; iz < Z.size() && Z[iz] <= blocks[i].ze; ++iz)
                    floodArray[ix][iy][iz] = 1;
    }
}

int main() {
    freopen("read.in", "r", stdin);

    int n;
    cin >> n;
    while (n--) {
        X.clear();
        Y.clear();
        Z.clear();
        memset(floodArray, 0, sizeof(floodArray));

        int blockNum;
        cin >> blockNum;
        for (int i = 0; i < blockNum; ++i) {
            cin >> blocks[i].x0 >> blocks[i].y0 >> blocks[i].z0 >> blocks[i].xe >> blocks[i].ye >> blocks[i].ze;
            blocks[i].xe += blocks[i].x0;
            blocks[i].ye += blocks[i].y0;
            blocks[i].ze += blocks[i].z0;
            X.push_back(blocks[i].x0);
            X.push_back(blocks[i].xe);
            Y.push_back(blocks[i].y0);
            Y.push_back(blocks[i].ye);
            Z.push_back(blocks[i].z0);
            Z.push_back(blocks[i].ze);
        }

        sort(X.begin(), X.end());
        sort(Y.begin(), Y.end());
        sort(Z.begin(), Z.end());
        X.resize(unique(X.begin(), X.end()) - X.begin());
        Y.resize(unique(Y.begin(), Y.end()) - Y.begin());
        Z.resize(unique(Z.begin(), Z.end()) - Z.begin());
        draw(blockNum);

        volume = (X.back() - X[0]) * (Y.back() - Y[0]) * (Z.back() - Z[0]);
        s = 0;
        // recalculate interval
        for (auto rit = X.rbegin(); rit != X.rend() - 1; ++rit)
            *rit -= *(rit + 1);
        for (auto rit = Y.rbegin(); rit != Y.rend() - 1; ++rit)
            *rit -= *(rit + 1);
        for (auto rit = Z.rbegin(); rit != Z.rend() - 1; ++rit)
            *rit -= *(rit + 1);
        X[0] = Y[0] = Z[0] = 0;
        X.push_back(0);
        Y.push_back(0);
        Z.push_back(0);

        dfs(0, 0, 0);

        cout << s << " " << volume << endl;
    }
}
