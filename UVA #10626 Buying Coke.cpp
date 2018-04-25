#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;

int c, totalMoney, mem[155][255][55];
int minCoins(int num, int fives, int tens){
    if (num == c) return 0;
    int &ret = mem[num][fives][tens];
    if (ret != -1) return ret;
    int ones = (totalMoney - 8*num) - 5*fives - 10*tens; // "ones" can be deduced from the other variables
    ret = INF;
    if (tens && ones > 2) ret = min(ret, minCoins(num+1,fives+1,tens-1) + 4); // 10,1,1,1 -> 5
    if (tens) ret = min(ret, minCoins(num+1,fives,tens-1) + 1); // 10 -> 1,1
    if (fives > 1) ret = min(ret, minCoins(num+1,fives-2,tens) + 2); // 5,5 -> 1,1
    if (fives && ones > 2) ret = min(ret, minCoins(num+1,fives-1,tens) + 4); // 5,1,1,1 -> 0
    if (ones > 7) ret = min(ret, minCoins(num+1,fives,tens) + 8); // 1,1,1,1,1,1,1,1 -> 0
    return ret;
}

int main(){
    int t;
    scanf("%d", &t);
    while (t--){
        int x, y, z;
        memset(mem,-1,sizeof(mem));
        scanf("%d %d %d %d", &c, &x, &y, &z);
        totalMoney = x + y*5 + z*10;
        printf("%d\n", minCoins(0,y,z));
    }
    return 0;
}
