#include <bits/stdc++.h>
using namespace std;
#define s second

int n;
vector <int> lis;
vector <pair <int,int>> vc;

int LIS() {
    lis.clear();
    for (int i = 0; i < n; i++) {
        int pos = upper_bound(lis.begin(), lis.end(), vc[i].s) - lis.begin();

        if (pos == lis.size()) lis.push_back(vc[i].s);
        else lis[pos] = vc[i].s;
    }
    return lis.size();
}

int main () {
    while (scanf("%d", &n) && n) {
        vc.clear();
        for (int i = 0, l, m; i < n; i++) {
            scanf("%d %d", &l, &m);
            vc.push_back (make_pair(l,m));
        }
        sort(vc.begin(), vc.end());
        printf ("%d\n", LIS());
    }
    printf("*\n");
}
