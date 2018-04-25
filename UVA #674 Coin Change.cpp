#include <bits/stdc++.h>
using namespace std;

int main(){
    int k, coins[5];
    coins[0] = 1, coins[1] = 5, coins[2] = 10, coins[3] = 25, coins[4] = 50;
    int dp[5][7500] = {0};
    for (int i = 0; i < 5; i++) dp[i][0] = 1;
    for (int trgt = 1; trgt < 7500; trgt++){
        for (int idx = 0; idx < 5; idx++){
            if (idx) dp[idx][trgt] = dp[idx-1][trgt];
            if (trgt >= coins[idx]) dp[idx][trgt] += dp[idx][trgt-coins[idx]];
        }
    }
    while ((scanf("%d", &k)) != EOF){
        printf("%d\n", dp[4][k]);
    }
    return 0;
}
