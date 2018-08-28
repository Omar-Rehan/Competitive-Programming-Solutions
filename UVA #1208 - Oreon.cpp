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

    bool isIsolated(int node) {
        vector<vector<int>> vc(parents.size());
        for (int i = 0; i < vc.size(); i++)
            vc[findSet(i)].push_back(i);
        return (vc[findSet(node)].size() == 1);
    }
};

struct edge {
    int from, to, w;
    edge(int from, int to, int w): from(from), to(to), w(w) {}
    bool operator < (const edge &e) const {return w > e.w;}
};

pair<int, vector<edge>> MST_Kruskal(vector<edge> edgeList, int n) {
    UnionFind uf(n);
    vector<edge> edges;
    int mstCost = 0;
    priority_queue<edge> pq;
    for (int i = 0; i < edgeList.size(); i++) pq.push(edgeList[i]);
    while(!pq.empty()) {
        edge e = pq.top(); pq.pop();
        if (uf.isIsolated(e.from) || uf.isIsolated(e.to)) {
            uf.unionSets(e.from, e.to);
            mstCost += e.w;
            edges.push_back(e);
        }
    }
    if (edges.size() != n-1)
        return make_pair(INF, vector<edge>());
    return make_pair(mstCost, edges);
}

int main() {
    int t, n, w;
    scanf("%d", &t);
    for (int q = 1; q <= t; q++) {
        scanf("%d", &n);
        vector<edge> vc;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j != n-1) scanf("%d,", &w);
                else scanf("%d", &w);

                if (w) vc.push_back(edge(i, j, w));
            }
        }

        vector<edge> mst = MST_Kruskal(vc, n).second;
        printf("Case %d:\n", q);
        for (auto e : mst) {
            printf("%c-%c %d\n", 'A' + min(e.from, e.to), 'A' + max(e.from, e.to), e.w);
        }
    }
}
