#include <bits/stdc++.h>
using namespace std;
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
        return w < e.w;
    }
};

int strt, fnsh;
vector<edge> edgeList;
vector<vector<edge>> edges;
void Kruskal(int n) {
    UnionFind uf(n);
    edges.clear(); edges.resize(n);
    priority_queue<edge> q;
    for (int i = 0; i < edgeList.size(); i++)
        q.push(edgeList[i]);
    while (!q.empty()) {
        edge e = q.top(); q.pop();
        if (uf.union_sets(e.from, e.to)) {
            edges[e.from].push_back(e);
            edges[e.to].push_back(edge(e.to, e.from, e.w));
        }
    }
}

int DFS(int node, int par, int mnSoFar) {
    if (node == fnsh) return mnSoFar;
    int ret = INF;
    for (int i = 0; i < edges[node].size(); i++) {
        edge child = edges[node][i];
        if (child.to == par) continue;
        ret = min(ret, DFS(child.to, node, min(mnSoFar, child.w)));
    }
    return ret;
}

int main() {
    int v, e, w, cs = 0;
    char c1[35], c2[35];
    while (scanf("%d %d", &v, &e) && (v || e)) {
        cs++;
        edgeList.clear();
        map<string, int> mp;
        for (int i = 0; i < e; i++) {
            scanf("\n%s %s %d", &c1, &c2, &w);
            if (mp.find(c1) == mp.end()) mp[c1] = mp.size();
            if (mp.find(c2) == mp.end()) mp[c2] = mp.size();
            edgeList.push_back(edge(mp[c1], mp[c2], w));
        }
        scanf("\n%s %s", &c1, &c2);
        strt = mp[c1], fnsh = mp[c2];
        Kruskal(v);
        printf("Scenario #%d\n%d tons\n\n", cs, DFS(strt, -1, INF));
    }
}
