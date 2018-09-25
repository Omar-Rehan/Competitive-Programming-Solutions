#include <bits/stdc++.h>
using namespace std;

int GCD(int a, int b) {
    return (b ? GCD(b, a%b) : a);
}

int main() {
    int n, G;
    while (scanf("%d", &n) && n) {
        G = 0;
        for (int i = 1; i < n; i++)
            for (int j = i+1; j <= n; j++) G += GCD(j, i);
        printf("%d\n", G);
    }
}
