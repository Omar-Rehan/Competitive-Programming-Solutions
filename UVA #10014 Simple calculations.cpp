#include<bits/stdc++.h>
using namespace std;

int main() {
    int t, n;
    double a, z;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %lf %lf", &n, &a, &z);
        double c[n];
        for (int i = 0; i < n; i++) {
            scanf("%lf", &c[i]);
            if (i) c[i] += c[i-1];
        }
        printf("%.2lf\n", (n*a + z - 2*accumulate(c, c+n, 0.0)) / (n+1));
        if (t) printf("\n");
    }
}
