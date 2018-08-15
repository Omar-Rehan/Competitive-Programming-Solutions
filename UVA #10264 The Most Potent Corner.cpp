#include <bits/stdc++.h>
using namespace std;

int flipBit(int num, int idx) {
    return num ^ (1 << idx);
}

int main() {
    int n, weight[1 << 15], potency[1 << 15];
    while (scanf("%d", &n) != EOF) {
        for (int crnr = 0; crnr < (1 << n); crnr++) 
          scanf("%d", &weight[crnr]);

        memset(potency, 0, sizeof potency);
        for (int crnr = 0; crnr < (1 << n); crnr++) {
            for (int bit = 0; bit < n; bit++) {
                int neighbour = flipBit(crnr, bit);
                potency[crnr] += weight[neighbour];
            }
        }

        int res = 0;
        for (int crnr = 0; crnr < (1 << n); crnr++) {
            for (int bit = 0; bit < n; bit++) {
                int neighbour = flipBit(crnr, bit);
                res = max(res, potency[crnr] + potency[neighbour]);
            }
        }
        printf("%d\n", res);
    }
}
