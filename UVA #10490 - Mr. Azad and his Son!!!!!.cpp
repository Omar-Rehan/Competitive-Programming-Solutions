#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> perfects = {6, 28, 496, 8128, 33550336, 8589869056, 137438691328, 2305843008139952128};
bool isPerfect(ll x) {
    return (find(perfects.begin(), perfects.end(), x) != perfects.end());
}

vector<bool> Seive() {
    vector<bool> primes(41, 1);
    primes[0] = primes[1] = 0;
    for (int i = 2; i*i <= 40; i++) {
        if (primes[i])
            for (int j = i*i; j <= 40; j += i) primes[j] = 0;
    }
    return primes;
}

int main() {
    int n;
    vector<bool> primes = Seive();
    while(scanf("%d", &n) && n) {
        ll x = ((ll)1 << (n-1)) * (((ll)1 << n) - 1);
        if (isPerfect(x)) printf("Perfect: %lld!\n", x);
        else if (primes[n]) printf("Given number is prime. But, NO perfect number is available.\n");
        else printf("Given number is NOT prime! NO perfect number is available.\n");
    }
}
