#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
const double EPS = 1e-8;

int n, m, tbl[15][105], mem[15][105];
int dp(int crs, int hrs) {
    if (crs == n) return 0;
    int &ret = mem[crs][hrs];
    if (ret != -1) return ret;
    for (int i = 1; i <= hrs - (n-crs-1); i++)
        ret = max(ret, tbl[crs][i] >= 5 ? tbl[crs][i] + dp(crs+1, hrs-i) : -1);
    return ret;
}

int main(){
    int t;
    scanf("%d", &t);
    while (t--) {
        int minReq = 0;
        bool noHope = false;
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++) {
            bool frstPassFound = false;
            for (int j = 1; j <= m; j++) {
                scanf("%d", &tbl[i][j]);
                if (!frstPassFound && tbl[i][j] >= 5) minReq += j, frstPassFound = true;
            }
            if (!frstPassFound) noHope = true;
        }
        if (minReq > m || noHope) {
            printf("Peter, you shouldn't have played billiard that much.\n");
            continue;
        }
        memset(mem,-1,sizeof mem);
        printf("Maximal possible average mark - %0.2lf.\n", 1.0 * (dp(0,m)+EPS) / n);
    }
}
