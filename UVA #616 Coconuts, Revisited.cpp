#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, tmp;
    while (scanf("%d", &n) && n >= 0) {
        bool b = false;
        for (k = 5; k > 1 && !b; k--) {
            tmp = n-1;
            b = !((n-1)%k);
            for (int i = 0; i < k; i++) {
                tmp = tmp/k * (k-1);
                b &= (i == k-1 ? tmp%k == 0 : tmp%k == 1);
            }
        }
        if (b) printf("%d coconuts, %d people and 1 monkey\n", n, k+1);
        else printf("%d coconuts, no solution\n", n);
    }
}
