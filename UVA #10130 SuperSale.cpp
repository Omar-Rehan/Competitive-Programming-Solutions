#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;

int n, wg[1005], pr[1005], mem[1005][35];
int dp(int obj, int cap) {
    if (cap < 0) return -INF;
    if (obj == n) return 0;
    int &ret = mem[obj][cap];
    if (ret != -1) return ret;
    return ret = max(pr[obj] + dp(obj+1, cap-wg[obj]), dp(obj+1, cap));
}

int main(){
    int t, g, x, y;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &x, &y);
            pr[i] = x, wg[i] = y;
        }
        int res = 0;
        scanf("%d", &g);
        memset(mem,-1,sizeof mem);
        while (g--) {
            scanf("%d", &x);
            res += dp(0, x);
        }
        printf("%d\n", res);
    }
}
