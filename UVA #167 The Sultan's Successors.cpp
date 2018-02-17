#include<bits/stdc++.h>
using namespace std;

int n, res, grid[10][10];
bool cols[8] = {0}, diagL[15] = {0}, diagR[15] = {0};

void rec(int row, int sum) {
    if (row == 8) {
        res = max(res, sum);
        return;
    }
    for (int col = 0; col < 8; col++) {
        if (!cols[col] && !diagL[row+col] && !diagR[row-col+7]) {
            cols[col] = diagL[row+col] = diagR[row-col+7] = 1;
            rec(row+1, sum + grid[row][col]);
            cols[col] = diagL[row+col] = diagR[row-col+7] = 0;
        }
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) scanf("%d", &grid[i][j]);
        }
        res = 0;
        rec(0,0);
        printf("%5d\n", res);
    }
}
