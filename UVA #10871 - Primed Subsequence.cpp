#include <bits/stdc++.h>
using namespace std;
const int MAX = (1e7);

vector<bool> prime(MAX + 1, 1);
void Sieve() {
    prime[0] = prime[1] = 0;
    for (int i = 2; i*i <= MAX; i++) {
        if (prime[i])
            for (int j = i*i; j <= MAX; j += i) prime[j] = 0;
    }
}

bool isPrime(int n) {
    if (n <= MAX) return prime[n];
    
    for (int i = 2; i*i <= n; i++)
        if (n%i == 0) return false;
    return true;
}

int main() {
    int t, n;
    scanf("%d", &t);
    Sieve();
    while (t--) {
        scanf("%d", &n);
        int cumArr[n+1] = {0};
        for (int i = 1; i <= n; i++) {
            scanf("%d", &cumArr[i]);
            cumArr[i] += cumArr[i-1];
        }

        int res = MAX, p1 = -1, p2 = -1;
        for (int i = 1; i <= n; i++) {
            for (int j = i+1; j <= n && (j - i + 1) < res; j++) {
                if (isPrime(cumArr[j] - cumArr[i-1])) {
                    res = j - i + 1;
                    p1 = i;
                    p2 = j;
                }
            }
        }

        if (res == MAX) printf("This sequence is anti-primed.\n");
        else {
            printf("Shortest primed subsequence is length %d:", res);
            for (int i = p1; i <= p2; i++) printf(" %d", cumArr[i] - cumArr[i-1]);
            printf("\n");
        }
    }
}
