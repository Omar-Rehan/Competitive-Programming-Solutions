#include <bits/stdc++.h>
using namespace std;

int pwr(int b, int p, int m) {
    if (!p) return 1;

    int sq = pwr(b, p >> 1, m);
    sq = (sq * sq) % m;

    if (p&1) sq = (sq * b) % m;

    return sq;
}

int main() {
    int b, p, m;
    while (scanf("%d %d %d", &b, &p, &m) != EOF)
        printf("%d\n", pwr(b%m, p, m));
}
