#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAX = (1e6);

vector<ll> primes;
void Sieve() {
    vector<bool> prime(MAX + 1, 1);
    prime[0] = prime[1] = 0;
    for (ll i = 2; i*i <= MAX; i++) {
        if (prime[i])
            for (ll j = i*i; j <= MAX; j += i) prime[j] = 0;
    }

    for (ll i = 2; i <= MAX; i++) {
        if (prime[i]) primes.push_back(i);
    }
}

ll numOfWays(ll n) {
    ll ret = 0;
    for (auto p : primes) {
        if (p > n) break;
        else if (p < n/2) ret--; // one of the numbers to be added to ret is the p itself

        // add the number of primes that if summed with p won't exceed n
        ret += upper_bound(primes.begin(), primes.end(), n-p) - primes.begin();
    }
    return ret / 2;
}

int main() {
    ll n, testCase = 1;
    Sieve();
    while (scanf("%lld", &n) && n) {
        printf("Case %lld: %lld\n", testCase++, numOfWays(n));
    }
}
