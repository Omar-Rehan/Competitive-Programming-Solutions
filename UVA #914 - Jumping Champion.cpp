#include <bits/stdc++.h>
using namespace std;

vector<int> Seive() {
    vector<bool> prime(2 * (1e6) + 2, 1);
    prime[0] = prime[1] = 0;
    for (int i = 2; i*i <= 2*(1e6); i++) {
        if (prime[i])
            for (int j = i*i; j <= 2*(1e6); j += i) prime[j] = 0;
    }

    vector<int> ret;
    for (int i = 2; i < 2*(1e6); i++)
        if (prime[i]) ret.push_back(i);
    return ret;
}

int main() {
    int t, L, U;
    scanf("%d", &t);
    vector<int> primes = Seive();
    while (t--) {
        scanf("%d %d", &L, &U);
        int lwr = (lower_bound(primes.begin(), primes.end(), L) - primes.begin());
        int upr = (upper_bound(primes.begin(), primes.end(), U) - primes.begin()) - 1;

        map<int,int> freqMap;
        for (int i = lwr; i < upr; i++) {
            freqMap[primes[i+1] - primes[i]]++;
        }

        bool valid = (upr > lwr);
        int diff, mx = 0;
        for (auto e : freqMap) {
            if (e.second > mx) {
                valid = true;
                diff = e.first;
                mx = e.second;
            } else if (e.second == mx) {
                valid = false;
            }
        }

        if (!valid) printf("No jumping champion\n");
        else printf("The jumping champion is %d\n", diff);
    }
}
