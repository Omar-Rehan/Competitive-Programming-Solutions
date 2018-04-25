#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1000000000;

int k, coins[6], change[45];
int buildChange(){
    change[0] = 0;
    for (int i = 1; i < 45; i++){
        change[i] = INF;
        for (int j = 0; j < 6; j++){
            change[i] = min(change[i], i >= coins[j] ? change[i - coins[j]] : INF);
        }
        change[i]++;
    }
}

int minCoins(int rem, int ones, int twos, int fours, int tens, int twenties, int fourties){
    if (rem <= 0) return change[-rem];
    int ret = INF;
    if (ones) ret = min(ret,minCoins(rem-1,ones-1,twos,fours,tens,twenties,fourties)+1);
    if (twos) ret = min(ret,minCoins(rem-2,ones,twos-1,fours,tens,twenties,fourties)+1);
    if (fours) ret = min(ret,minCoins(rem-4,ones,twos,fours-1,tens,twenties,fourties)+1);
    if (tens) ret = min(ret,minCoins(rem-10,ones,twos,fours,tens-1,twenties,fourties)+1);
    if (twenties) ret = min(ret,minCoins(rem-20,ones,twos,fours,tens,twenties-1,fourties)+1);
    if (fourties) ret = min(ret,minCoins(rem-40,ones,twos,fours,tens,twenties,fourties-1)+1);
    return ret;
}

int main(){
    coins[0] = 1, coins[1] = 2, coins[2] = 4, coins[3] = 10, coins[4] = 20, coins[5] = 40;
    buildChange();
    while (true){
        int x, a, b, c, d, e, f;
        double db;
        scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
        if (!a && !b && !c && !d && !e && !f) break;
        scanf("%lf", &db);
        db *= 20;
        x = db;
        printf("%3d\n", minCoins(x,a,b,c,d,e,f));
    }
    return 0;
}
