#include<bits/stdc++.h>
using namespace std;

int pwr(int b, int p) {
    if (!p) return 1;
    int sq = pwr(b, p>>1);
    sq *= sq;
    if (p&1) sq *= b;
    return sq;
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        
        int num = 0, k = 9, h = 1;
        while (h <= n) {
            h += (num+1)*k;
            k *= 10;
            num++;
        }
        h -= num*(k/10);
        
        int dist = n - h;
        int r = (dist / num) + pwr(10,num-1);
        int t = num - (dist % num)- 1;
        while (t--) r /= 10;

        printf("%d\n", r%10);
    }
}
