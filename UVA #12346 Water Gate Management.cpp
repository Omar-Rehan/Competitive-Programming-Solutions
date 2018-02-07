#include<bits/stdc++.h>
using namespace std;
#define INF 1000000000

int n, t, v, arr[25][2];
int rec(int idx, int vol, int cst, int tm) {
    if (vol >= v) return cst;
    if (idx == n) return INF;
    int ret = INF;
    for (int h = 0; h <= t; h++)
        ret = min(ret, rec(idx+1, vol + h*arr[idx][0], cst + (h > 0)*arr[idx][1], tm+h));
    return ret;
}

int main() {
    int m;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d %d", &arr[i][0], &arr[i][1]);
    scanf("%d", &m);
    for (int q = 1; q <= m; q++) {
        scanf("%d %d", &v, &t);
        int res = rec(0,0,0,0);
        if (res == INF) printf("Case %d: IMPOSSIBLE\n", q);
        else printf("Case %d: %d\n", q, res);
    }
}
