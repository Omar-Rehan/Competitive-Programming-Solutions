#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll; // must be unsigned
const ll MAX = 70000; // all powers start from 4, therefore 70000 is enough to cover all super power numbers

vector<ll> nonPrimes;
void Sieve() {
    vector<bool> prime(MAX + 1, 1);
    prime[0] = prime[1] = 0;
    for (ll i = 2; i*i <= MAX; i++) {
        if (prime[i])
            for (ll j = i*i; j <= MAX; j += i) prime[j] = 0;
    }

    for (ll i = 2; i <= MAX; i++) {
        if (!prime[i]) nonPrimes.push_back(i);
    }
}

ll pwr(ll b, ll p) {
    if (!p) return 1;
    ll sq = pwr(b, p >> 1);
    sq *= sq;
    if (p&1) sq *= b;
    return sq;
}

set<ll> SuperPowerNumbers = {1};
void genSuperPowerNumbers() {
    Sieve();
    for (ll i = 2; i < MAX; i++) { // bases
        ll lim = (ll)floor(log((ll)-1) / log(i)); // largest power possible
        for (auto e : nonPrimes) { // powers
            if (e <= lim) SuperPowerNumbers.insert(pwr(i, e));
            else break;
        }
    }
}

int main() {
    genSuperPowerNumbers();
    for (auto e : SuperPowerNumbers)
        if (e) printf("%llu\n", e);
}
