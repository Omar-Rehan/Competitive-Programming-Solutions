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
    bool valid;
    edge(int from, int to, int w, bool valid): from(from), to(to), w(w), valid(valid) {}
    bool operator < (const edge &e) const {return w > e.w;}
    bool operator == (const edge &e) const {return ((from == e.from) && (to == e.to) && (w == e.w));}
};

pair<int, vector<edge>> MST_Kruskal(vector<edge> edgeList, int n) {
    UnionFind uf(n);
    vector<edge> edges;
    int mstCost = 0;
    priority_queue<edge> pq;
    for (int i = 0; i < edgeList.size(); i++) pq.push(edgeList[i]);
    while(!pq.empty()) {
        edge e = pq.top(); pq.pop();
        if (e.valid && uf.unionSets(e.from, e.to)) {
            mstCost += e.w;
            edges.push_back(e);
        }
    }
    if (edges.size() != n-1)
        return make_pair(INF, vector<edge>());
    return make_pair(mstCost, edges);
}

int main() {
    int t, v, e, x, y, w;
    scanf("%d", &t);
    for (int q = 1; q <= t; q++) {
        scanf("%d %d", &v, &e);
        
        vector<edge> vc;
        while (e--) {
            scanf("%d %d %d", &x, &y, &w);
            vc.push_back(edge(x-1, y-1, w, 1));
        }
        pair<int, vector<edge>> mst = MST_Kruskal(vc, v);

        if (mst.first == INF) {
            printf("Case #%d : No way\n", q);
        } else {
            int res = INF;
            for (int i = 0; i < vc.size(); i++) {
                if (find(mst.second.begin(), mst.second.end(), vc[i]) != mst.second.end()) {
                    vc[i].valid = false;
                    res = min(res, MST_Kruskal(vc, v).first);
                    vc[i].valid = true;
                }
            }
            if (res == INF) printf("Case #%d : No second way\n", q);
            else printf("Case #%d : %d\n", q, res);
        }
    }
}
