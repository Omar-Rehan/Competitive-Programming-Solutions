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

double MST_Kruskal(vector<edge> edgeList, int n, int s) {
    UnionFind uf(n);
    vector<double> edges;
    priority_queue<edge> pq;
    for (int i = 0; i < edgeList.size(); i++) pq.push(edgeList[i]);
    while(!pq.empty()) {
        edge e = pq.top(); pq.pop();
        if (uf.unionSets(e.from, e.to)) {
            edges.push_back(e.w);
        }
    }

    sort(edges.rbegin(), edges.rend());
    return edges[s-1];
}

int main() {
    int t, n, s;
    double w;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &s, &n);
        int pos[n][2];
        vector<edge> vc;
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &pos[i][0], &pos[i][1]);
        }

        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                w = hypot(pos[i][0]-pos[j][0], pos[i][1]-pos[j][1]);
                vc.push_back(edge(i, j, w));
            }
        }

        printf("%0.2lf\n", MST_Kruskal(vc, n, s));
    }
}
