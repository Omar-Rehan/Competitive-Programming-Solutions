#include<bits/stdc++.h>
using namespace std;

char arr[102][102];
int acc[102][102];

int calc(int ULX, int ULY, int LRX, int LRY) {
    return (acc[LRX][LRY] - acc[ULX-1][LRY] - acc[LRX][ULY-1] + acc[ULX-1][ULY-1]);
}

int main() {
    int n, m, res;
    while(scanf("%d", &n) && n) {
        // Take in input
        scanf("%d", &m);
        memset(arr,0,sizeof arr);
        for (int i = 1; i <= n; i++) {
            scanf("\n");
            for (int j = 1; j <= m; j++) scanf("%c", &arr[i][j]);
        }

        // Accumulate
        memset(acc,0,sizeof acc);
        for (int x = 1; x <= n; x++) for (int y = 1; y <= m; y++)
            acc[x][y] = (arr[x][y] == '1') + acc[x-1][y] + acc[x][y-1] - acc[x-1][y-1];

        // Traverse & Maximize
        res = 0;
        for (int x = 1; x <= n; x++) {
            for (int y = 1; y <= m; y++) {
                if (!arr[x][y]) continue;
                for (int r = x; r <= n; r++) {
                    if (!arr[r][y]) break;
                    for (int c = y; c <= m; c++) {
                        if (calc(x,y,r,c) == (r-x+1)*(c-y+1)) res++;
                        else break;
                    }
                }
            }
        }

        // Print output
        printf("%d\n", res);
    }
}
