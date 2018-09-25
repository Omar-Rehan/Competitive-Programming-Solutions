#include <bits/stdc++.h>
using namespace std;

int GCD(int a, int b) {
    return (b ? GCD(b, a%b) : a);
}

int main() {
    int t, gcd, lcm;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &gcd, &lcm);
        if (lcm % gcd) {
            printf("-1\n");
            continue;
        }

        lcm /= gcd;
        int a, b = -1;
        for (int i = 1; i*i <= lcm; i++) {
            if (lcm % i) continue;
            int j = lcm / i;
            if (GCD(j, i) == 1) {
                a = i * gcd;
                b = j * gcd;
                break;
            }
        }

        if (a == -1) printf("-1\n");
        else printf("%d %d\n", a, b);
    }
}
