#include <bits/stdc++.h>
using namespace std;

vector<int> Seive() {
    vector<bool> primes((1e4) + 1, 1);
    primes[0] = primes[1] = 0;
    for (int i = 2; i*i <= (1e4); i++) {
        if (primes[i]) {
            for (int j = i*i; j <= (1e4); j += i) primes[j] = 0;
        }
    }

    vector<int> ret;
    for (int i = 2; i < (1e4); i++)
        if (primes[i]) ret.push_back(i);
    return ret;
}

int main() {
    int t, n;
    scanf("%d", &t);
    vector<int> primes = Seive();
    while(t--) {
        int mx = 0, ans = -1;
        scanf("%d", &n);
        for (int idx = 0; idx < primes.size(); idx++) {
            int x = primes[idx];
            for (int p = 1; p*x <= n; p++) {
                if ((p+1)*x > n && mx < (n - p*x)) {
                    mx = n - p*x;
                    ans = x;
                }
            }
        }
        printf("%d\n", ans);
    }
}
