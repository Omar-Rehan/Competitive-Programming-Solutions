#include <bits/stdc++.h>
using namespace std;

const int MAX = 100002;
int arr[MAX], tree[4*MAX], lazy[4*MAX];
int Merge(int a, int b) {return a * b;}

void Build(int p, int l, int r) {
    if (l == r) {
        tree[p] = arr[l];
        return;
    }
    int mid = (l + r) / 2;
    Build(2*p , l, mid);
    Build(2*p+1, mid+1, r);
    tree[p] = Merge(tree[2*p], tree[2*p+1]);
}

int Query(int p, int l, int r, int x, int y) {
    if (l > y || r < x) return 1;
    if (l >= x && r <= y) return tree[p];
    int mid = (l + r) / 2;
    int q1 = Query(2*p, l, mid, x, y);
    int q2 = Query(2*p+1, mid+1, r, x, y);
    return Merge(q1, q2);
}

void Update(int p, int l, int r, int idx, int val) {
    if (l > idx || r < idx) return;
    if (idx == l && idx == r) {
        tree[p] = val;
        return;
    }
    int mid = (l + r) / 2;
    Update(2*p, l, mid, idx, val);
    Update(2*p+1, mid+1, r, idx, val);
    tree[p] = Merge(tree[2*p], tree[2*p+1]);
}

int main () {
    int n, k;
    char cc;
    while (scanf("%d %d", &n, &k) != EOF) {
        for (int i = 1; i <= n; i++) {
            scanf("%d", &arr[i]);
            arr[i] = (arr[i] ? arr[i] / abs(arr[i]) : 0);
        }
        Build(1, 1, n);
        while (k--) {
            scanf("\n%c", &cc);
            if (cc == 'P') {
                int s, e;
                scanf("%d %d", &s, &e);
                int q = Query(1, 1, n, s, e);
                printf("%c", (q ? (q > 0 ? '+' : '-') : '0'));
            } else {
                int idx, val;
                scanf("%d %d", &idx, &val);
                if (val) val /= abs(val);
                Update(1, 1, n, idx, val);
            }
        }
        printf("\n");
    }
}
