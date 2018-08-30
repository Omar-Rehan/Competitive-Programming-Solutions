#include <bits/stdc++.h>
using namespace std;

vector<bool> primes((1e6) + 2, 1);
bool digitPrime(int n) {
    int sum = 0;
    while(n) sum += n%10, n /= 10;
    return primes[sum];
}

vector<int> Seive() {
    primes[0] = primes[1] = 0;
    for (int i = 2; i*i <= (1e6); i++) {
        if (primes[i]) {
            for (int j = i*i; j <= (1e6); j += i) primes[j] = 0;
        }
    }

    vector<int> ret((1e6) + 2, 0);
    for (int i = 1; i <= (1e6); i++) ret[i] = (primes[i] && digitPrime(i)) + ret[i-1];
    return ret;
}

int main() {
    int n, l, r;
    scanf("%d", &n);
    vector<int> cumVector = Seive();
    while(n--) {
        scanf("%d %d", &l, &r);
        printf("%d\n", cumVector[r] - cumVector[l-1]);
    }
}
