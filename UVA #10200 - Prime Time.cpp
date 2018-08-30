#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double EPS = (1e-6);

bool isPrime(ll n) {
    for (ll i = 2; i*i <= n; i++) {
        if (n%i == 0) return false;
    }
    return true;
}

vector<bool> Seive() {
    vector<bool> primes((1e7) + 1, 1);
    primes[0] = primes[1] = 0;
    for (int i = 2; i*i <= (1e7); i++) {
        if (primes[i]) {
            for (int j = i*i; j <= (1e7); j += i) primes[j] = 0;
        }
    }
    return primes;
}

int main() {
    vector<bool> primes = Seive();
    int a, b, cumArr[10001] = {0};
    cumArr[0] = 1;
    for (ll i = 1; i <= (1e4); i++) {
        cumArr[i] = cumArr[i-1];
        ll tmp = i*i + i + 41;
        if (tmp <= (1e7)) cumArr[i] += primes[tmp];
        else cumArr[i] += isPrime(tmp);
    }

    while(scanf("%d %d", &a, &b) != EOF) {
        double formulaCnt = (cumArr[b] - (!a ? 0 : cumArr[a-1])) + EPS;
        printf("%0.2lf\n", 100.0 * formulaCnt / (b - a + 1));
    }
}
