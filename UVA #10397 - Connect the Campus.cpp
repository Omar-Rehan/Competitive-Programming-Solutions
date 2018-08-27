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
    int from, to;
    double w;
    edge(int from, int to, double w): from(from), to(to), w(w) {}
    bool operator < (const edge &e) const {return w > e.w;}
};

pair<double, vector<edge>> MST_Kruskal(vector<edge> edgeList, int n) {
    UnionFind uf(n);
    vector<edge> edges;
    double mstCost = 0.0;
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

int main() {
    int n, m, f, t;
    while (scanf("%d", &n) != EOF) {
        int b[n][2];
        for (int i = 0; i < n; i++)
            scanf("%d %d", &b[i][0], &b[i][1]);

        vector<edge> vc;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                vc.push_back(edge(i, j, hypot(b[i][0]-b[j][0], b[i][1]-b[j][1])));
            }
        }

        scanf("%d", &m);
        while(m--) {
            scanf("%d %d", &f, &t);
            vc.push_back(edge(f-1, t-1, 0.0));
        }

        printf("%0.2lf\n", MST_Kruskal(vc, n).first);
    }
}
