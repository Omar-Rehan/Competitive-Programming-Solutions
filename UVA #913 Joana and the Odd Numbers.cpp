#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n, r;
    while (scanf("%lld", &n) != EOF) {
        n -= 2;
        r = 1 + 2*((n>>1) + 1)*((n>>1) + 1);
        printf("%lld\n", 3*(r+2*n));
    }
}
