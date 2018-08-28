#include <bits/stdc++.h>
using namespace std;
const int INF = (1 << 30);

struct UnionFind {
    vector<int> ranks, parents;

    UnionFind(int n) {
        ranks = vector<int>(n), parents = vector<int>(n);
        for (int i = 0; i < n; i++) parents[i] = i, ranks[i] = 1;
    }

    int findSet(int x) {
        if (x == parents[x]) return x;
        return parents[x] = findSet(parents[x]);
    }

    void Link(int x, int y) {
        if (ranks[x] > ranks[y]) swap(x, y);
        parents[x] = y;
        if (ranks[x] == ranks[y]) ranks[y]++;
    }

    bool unionSets(int x, int y) {
        x = findSet(x), y = findSet(y);
        if (x != y) Link(x, y);
        return (x != y);
    }
};

struct edge {
    int from, to, w;
    edge(int from, int to, int w): from(from), to(to), w(w) {}
    bool operator < (const edge &e) const {return w < e.w;}
};

pair<int, vector<edge>> MST_Kruskal(vector<edge> edgeList, int n) {
    UnionFind uf(n);
    vector<edge> edges;
    int mstCost = 0;
    priority_queue<edge> pq;
    for (int i = 0; i < edgeList.size(); i++) pq.push(edgeList[i]);
    while(!pq.empty()) {
        edge e = pq.top(); pq.pop();
        if (uf.unionSets(e.from, e.to)) {
            mstCost += e.w;
            edges.push_back(e);
        }
    }
    if (edges.size() != n-1)
        return make_pair(-INF, vector<edge>());
    return make_pair(mstCost, edges);
}

int destination, source, res;
vector<edge> mst;
void DFS(int node, int par, int mn) {
    if (node == destination) {
        res = mn;
        return;
    }

    for (auto e : mst) {
        if (e.from == node && e.to != par)
            DFS(e.to, node, min(mn, e.w));
        if (e.to == node && e.from != par)
            DFS(e.from, node, min(mn, e.w));
    }
}

int main() {
    int n, m, f, t, w, testCase = 1;
    while(scanf("%d %d", &n, &m) && (n || m)) {
        vector<edge> vc;
        for (int i = 0; i < m; i++) {
            scanf("%d %d %d", &f, &t, &w);
            vc.push_back(edge(f-1, t-1, w)); // 1-indexed -> 0-indexed
        }
        mst = MST_Kruskal(vc, n).second;

        scanf("%d %d %d", &source, &destination, &w);
        source--; destination--; // 1-indexed -> 0-indexed

        DFS(source, -1, INF);
        res--; // the guide counts
        res = (int)ceil(1.0 * w / res);

        printf("Scenario #%d\nMinimum Number of Trips = %d\n\n", testCase, max(res, 0));

        testCase++;
        mst.clear();
    }
}
