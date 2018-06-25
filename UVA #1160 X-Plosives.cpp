#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    vector<int> ranks, parents;
    UnionFind(int n) {
        ranks = vector<int>(n), parents = vector<int>(n);
        for (int i = 0; i < n; i++) parents[i] = i, ranks[i] = 1;
    }
    int find_set(int x) {
        if (x == parents[x]) return x;
        return parents[x] = find_set(parents[x]);
    }
    void link(int x, int y) {
        if (ranks[x] > ranks[y]) swap(x, y);
        parents[x] = y;
        if (ranks[x] == ranks[y]) ranks[y]++;
    }
    bool union_sets(int x, int y) {
        x = find_set(x), y = find_set(y);
        if (x != y) link(x, y);
        return x != y;
    }
};

int main() {
    int x, y;
    while (scanf("%d", &x) != EOF) {
        int res = 0;
        UnionFind uf(100001);
        while (scanf("%d", &y)) {
            if (!uf.union_sets(x, y)) res++;
            scanf("%d", &x);
            if (x == -1) break;
        }
        printf("%d\n", res);
    }
}
