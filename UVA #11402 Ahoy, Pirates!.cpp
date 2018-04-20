#include <bits/stdc++.h>
using namespace std;

string str;
const int MAX = 1024002;
int SegTree[4*MAX], lazy[4*MAX];

void Build(int p, int l, int r) {
    if (l == r) {
        SegTree[p] = (str[l] == '1');
        return;
    }
    int mid = (l + r) / 2;
    Build(2*p, l, mid);
    Build(2*p+1, mid+1, r);
    SegTree[p] = SegTree[2*p] + SegTree[2*p+1];
}

void Propagate(int p, int l, int r) {
    if (lazy[p] != -1) {
        if (lazy[p] == 0) SegTree[p] = 0;
        else if (lazy[p] == 1) SegTree[p] = (r - l + 1);
        else if (lazy[p] == 2) SegTree[p] = (r - l + 1) - SegTree[p];
        
        if (l != r) {
            if (lazy[p] < 2) {
                lazy[2*p] = lazy[2*p+1] = lazy[p];
            } else { // lazy[p] == 2
                lazy[2*p] = (lazy[2*p] == 2 ? -1 : 1 - lazy[2*p]);
                lazy[2*p+1] = (lazy[2*p+1] == 2 ? -1 : 1 - lazy[2*p+1]);
            }
        }
        lazy[p] = -1;
    }
}

void Update(int p, int l, int r, int s, int e, int val) {
    Propagate(p, l, r);
    if (e < l || s > r) return;
    if (s <= l && r <= e) {
        if (val < 2) {
            lazy[p] = val;
        } else { // val == 2
            lazy[p] = (lazy[p] == 2 ? -1 : 1 - lazy[p]);
        }
        Propagate(p, l, r);
        return;
    }
    int mid = (l + r) / 2;
    Update(2*p, l, mid, s, e, val);
    Update(2*p+1, mid+1, r, s, e, val);
    SegTree[p] = SegTree[2*p] + SegTree[2*p+1];
}

int Query(int p, int l, int r, int s, int e) {
    Propagate(p, l, r);
    if (e < l || s > r) return 0;
    if (s <= l && r <= e) return SegTree[p];
    int mid = (l + r) / 2;
    int q1 = Query(2*p, l, mid, s, e);
    int q2 = Query(2*p+1, mid+1, r, s, e);
    return q1 + q2;
}

int main() {
    int cases, cnt, m, k, t, s, e;
    char ch, cc[55];
    scanf("%d", &cases);
    for (int q = 1; q <= cases; q++) {
        cnt = 0;
        str = "";
        scanf("%d", &m);
        printf("Case %d:\n", q);
        while (m--) {
            scanf("%d %s", &t, &cc);
            while (t--) str += cc;
        }
        int n = str.length();
        str = "2" + str;
        Build(1, 1, n);
        memset(lazy, -1, sizeof lazy);
        scanf("%d", &k);
        while (k--) {
            scanf("\n%c %d %d", &ch, &s, &e);
            s++, e++;
            if (ch == 'E') { // Barbary
                Update(1, 1, n, s, e, 0);
            } else if (ch == 'F') { // Buccaneer
                Update(1, 1, n, s, e, 1);
            } else if (ch == 'I') { // Reverse
                Update(1, 1, n, s, e, 2);
            } else { // Query
                cnt++;
                printf("Q%d: %d\n", cnt, Query(1, 1, n, s, e));
            }
        }
    }
}
