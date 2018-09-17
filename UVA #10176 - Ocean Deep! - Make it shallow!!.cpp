#include <bits/stdc++.h>
using namespace std;
const int MOD = 131071;

int main() {
    char c;
    int x = 0;
    while (scanf("%c", &c) != EOF) {
        if (c == '0' || c == '1') {
            x = ((x << 1) + (c == '1')) % MOD;
        } else if (c == '#') {
            if (x) printf("NO\n");
            else printf("YES\n");
            x = 0;
        }
    }
}
