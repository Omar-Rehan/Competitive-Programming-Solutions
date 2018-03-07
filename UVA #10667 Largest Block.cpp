#include<bits/stdc++.h>
using namespace std;

int arr[102][102], acc[102][102];

int calc(int ULX, int ULY, int LRX, int LRY) {
    return (acc[LRX][LRY] - acc[ULX-1][LRY] - acc[LRX][ULY-1] + acc[ULX-1][ULY-1]);
}

int main() {
    int t, n, sz, ULX, ULY, LRX, LRY, res;
    scanf("%d", &t);
    while(t--) {
        // Take in input
        memset(arr,0,sizeof arr);
        scanf("%d %d", &sz, &n);
        while (n--) {
            scanf("%d %d %d %d", &ULX, &ULY, &LRX, &LRY);
            for (int x = ULX; x <= LRX; x++) for (int y = ULY; y <= LRY; y++) arr[x][y] = 1;
        }

        // Accumulate
        memset(acc,0,sizeof acc);
        for (int x = 1; x <= sz; x++) for (int y = 1; y <= sz; y++)
            acc[x][y] = arr[x][y] + acc[x-1][y] + acc[x][y-1] - acc[x-1][y-1];

        // Traverse & Maximize
        res = 0;
        for (int x = 1; x <= sz; x++) {
            for (int y = 1; y <= sz; y++) {
                if (arr[x][y]) continue;
                for (int r = x; r <= sz; r++) {
                    if (arr[r][y]) break;
                    for (int c = y; c <= sz; c++) {
                        if (!calc(x,y,r,c)) res = max(res,(r-x+1)*(c-y+1));
                        else break;
                    }
                }
            }
        }

        // Print output
        printf("%d\n", res);
    }
}
