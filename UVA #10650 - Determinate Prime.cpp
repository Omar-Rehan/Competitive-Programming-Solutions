#include <bits/stdc++.h>
using namespace std;
const int lim = 35000;

vector<int> Seive() {
    vector<bool> primes(lim + 1, 1);
    primes[0] = primes[1] = 0;
    for (int i = 2; i*i <= lim; i++) {
        if (primes[i]) {
            for (int j = i*i; j <= lim; j += i) primes[j] = 0;
        }
    }

    vector<int> ret;
    for (int i = 2; i < lim; i++)
        if (primes[i]) ret.push_back(i);
    return ret;
}

int main() {
    int l, r;
    vector<int> primes = Seive();

    vector<vector<int>> detPrimes;
    for (int i = 0; i < primes.size()-2; i++) {
        if (primes[i+1] - primes[i] == primes[i+2] - primes[i+1]) {
            int diff = primes[i+1] - primes[i];
            detPrimes.push_back(vector<int>(1, primes[i]));

            while (i < primes.size()-1 && primes[i+1] - primes[i] == diff)
                detPrimes.back().push_back(primes[++i]);

            i--;
        }
    }

    while(scanf("%d %d", &l, &r) && (l || r)) {
        if (r < l) swap(l, r); // STUPID TRICK
        for (auto e : detPrimes) {
            if (l <= e.front() && e.back() <= r)
                for (auto f : e) printf("%d%c", f, (f == e.back() ? '\n' : ' '));
        }
    }
}
