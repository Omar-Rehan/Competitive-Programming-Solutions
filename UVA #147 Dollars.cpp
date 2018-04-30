#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double EPS = (1e-6);

const int n = 11, MAX_COIN = 30000 + 2;
int p = 0, coins[n] = {5,10,20,50,100,200,500,1000,2000,5000,10000};
ll dp[2][MAX_COIN];

void PreProcess() {
    dp[0][0] = dp[1][0] = 1;

    for (int idx = 0; idx < n; idx++, p = !p) {
        for (int rem = 5; rem < MAX_COIN; rem += 5) {
            ll &watch = dp[p][rem];
            if (!idx) {
                dp[p][rem] = 1;
            } else {
                if (rem >= coins[idx]) 
                    dp[p][rem] = dp[!p][rem] + dp[p][rem - coins[idx]];
                else dp[p][rem] = dp[!p][rem];
            }
        }
    }
}

int main() {
    double d;
    PreProcess();
    while (scanf("%lf", &d) && abs(d) > EPS) {
        int trgt = d * 100 + EPS;
        printf("%6.2lf%17lld\n", d, dp[!p][trgt]);
    }
}
