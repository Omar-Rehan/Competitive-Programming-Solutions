#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5, INF = 1e9;
int tree[4*MAX], maxi[4*MAX], mini[4*MAX], lazy[4*MAX];

void Propagate(int p, int l, int r) {
    if (lazy[p]) {
        tree[p] += r - l + 1;
        maxi[p] = max(lazy[p], maxi[p]);
        mini[p] = lazy[p];
        if (l != r) {
            int mid = (l + r) / 2;
            Propagate(2*p, l, mid);
            Propagate(2*p+1, mid+1, r);
            lazy[2*p] = lazy[2*p+1] = lazy[p];
        }
        lazy[p] = 0;
    }
}

void Update(int p, int l, int r, int s, int e, int h) {
    Propagate(p, l, r);
    if (e < l || s > r) return;
    if (s <= l && e >= r) {
        if (h >= maxi[p]) {
            lazy[p] = h;
            Propagate(p, l, r);
            return;
        } else if (h < mini[p]) {
            return;
        }
    }
    int mid = (l + r) / 2;
    Update(2*p, l, mid, s, e, h);
    Update(2*p+1, mid+1, r, s, e, h);
    tree[p] = tree[2*p] + tree[2*p+1];
    maxi[p] = max(maxi[2*p], maxi[2*p+1]);
    mini[p] = min(mini[2*p], mini[2*p+1]);
}

int main() {
    int t, n, l, r, h;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        memset(tree, 0, sizeof tree);
        memset(lazy, 0, sizeof lazy);
        memset(maxi, 0, sizeof maxi);
        memset(mini, 0, sizeof mini);
        while (n--) {
            scanf("%d %d %d", &l, &r, &h);
            Update(1, 1, MAX, l, r-1, h);
        }
        Propagate(1, 1, MAX);
        printf("%d\n", tree[1]);
    }
    scanf("%d", &n);
}
