#include<bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> ranks, parent;
    int forests;
    DSU(int n) {
        ranks = vector<int>(n), parent = vector<int>(n);
        forests = n;
        for (int i = 0; i < n; i++) parent[i] = i, ranks[i] = 1;
    }
    int FindParent(int x) {
        if (x == parent[x]) return x;
        return parent[x] = FindParent(parent[x]);
    }
    void Link(int x, int y) {
        if (ranks[x] > ranks[y]) swap(x,y);
        parent[x] = y;
        if (ranks[x] == ranks[y]) ranks[y]++;
    }
    bool UnionSets(int x, int y) {
        x = FindParent(x), y = FindParent(y);
        if (x != y) {Link(x, y); forests--;}
        return x != y;
    }
};

int main() {
    int t, n;
    double d;
    scanf("%d", &t);
    for (int q = 1; q <= t; q++) {
        scanf("%d %lf", &n, &d);
        d *= d;
        double arr[n][2];
        for (int i = 0; i < n; i++) scanf("%lf %lf", &arr[i][0], &arr[i][1]);
        DSU dsu(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if ((arr[i][0]-arr[j][0])*(arr[i][0]-arr[j][0]) + (arr[i][1]-arr[j][1])*(arr[i][1]-arr[j][1]) < d)
                    dsu.UnionSets(i,j);
            }
        }
        printf("Case %d: %d\n", q, dsu.forests);
    }
}
