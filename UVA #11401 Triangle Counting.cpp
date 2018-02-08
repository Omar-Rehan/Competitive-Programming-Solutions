#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n;
    while (scanf("%lld", &n) && n > 2) 
      printf("%lld\n", (n%2 ? (n-1)*(n-3)*(2*n-1)/24 : n*(n-2)*(2*n-5)/24));
}
