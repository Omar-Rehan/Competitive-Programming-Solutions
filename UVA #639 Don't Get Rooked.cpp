#include<bits/stdc++.h>
using namespace std;

int n, res;
char grid[10][10];

bool valid(int x, int y) {
    bool ret = true;
    for (int i = x+1; i < n; i++) {
        if (grid[i][y] == 'X') break;
        ret &= (grid[i][y] != 'O');
    }
    for (int i = x-1; i >= 0; i--) {
        if (grid[i][y] == 'X') break;
        ret &= (grid[i][y] != 'O');
    }
    for (int i = y+1; i < n; i++) {
        if (grid[x][i] == 'X') break;
        ret &= (grid[x][i] != 'O');
    }
    for (int i = y-1; i >= 0; i--) {
        if (grid[x][i] == 'X') break;
        ret &= (grid[x][i] != 'O');
    }
    return ret;
}

void rec(int num) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '.' && valid(i,j)) {
                grid[i][j] = 'O';
                rec(num+1);
                grid[i][j] = '.';
            }
        }
    }
    res = max(res,num);
}

int main() {
    while (scanf("%d", &n) && n) {
        for (int i = 0; i < n; i++) {
            scanf("\n");
            for (int j = 0; j < n; j++) scanf("%c", &grid[i][j]);
        }
        res = 0;
        rec(0);
        printf("%d\n", res);
    }
}
