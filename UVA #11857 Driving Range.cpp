#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = (1 << 30);

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

struct edge {
    int from, to, w;
    edge(int from, int to, int w): from(from), to(to), w(w) {}
    bool operator < (edge e) const {
        return w > e.w;
    }
};

vector<edge> edgeList;
pair<int, vector<edge>> Kruskal(int n) {
    UnionFind uf(n);
    vector<edge> edges;
    int mstCost = 0;
    priority_queue<edge> q;
    for (int i = 0; i < edgeList.size(); i++)
        q.push(edgeList[i]);
    while (!q.empty()) {
        edge e = q.top(); q.pop();
        if (uf.union_sets(e.from, e.to)) {
            mstCost += e.w;
            edges.push_back(e);
        }
    }
    if (edges.size() != n-1)
        return make_pair(-INF, vector<edge>());
    return make_pair(mstCost, edges);
}

int main() {
    int v, e, f, t, w;
    while (scanf("%d %d", &v, &e) && (v || e)) {
        edgeList.clear();
        for (int i = 0; i < e; i++) {
            scanf("%d %d %d", &f, &t, &w);
            edgeList.push_back(edge(f, t, w));
        }
        pair<int, vector<edge>> mst = Kruskal(v);
        if (mst.first == -INF) {
            printf("IMPOSSIBLE\n");
        } else {
            int res = -1;
            for (auto e : mst.second) res = max(res, e.w);
            printf("%d\n", res);
        }
    }
}
