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
    bool operator < (const edge &e) const {return w > e.w;}
};

int MST_Kruskal(vector<edge> edgeList, int n) {
    UnionFind uf(n);
    int mstCost = 0;
    priority_queue<edge> pq;
    for (int i = 0; i < edgeList.size(); i++) pq.push(edgeList[i]);
    
    while(!pq.empty()) {
        edge e = pq.top(); pq.pop();
        if (uf.unionSets(e.from, e.to)) mstCost += e.w;
    }
    
    return mstCost;
}

int main() {
    int n, m, t, w, cnt;
    string from, to;
    char c1[10], c2[10];
    map<string, int> mp;
    vector<edge> vc;
    scanf("%d", &t);
    while (t--) {
        cnt = 0;
        scanf("%d %d", &n, &m);

        for(int i = 0; i < m; i++) {
            scanf("%s %s %d", &c1, &c2, &w);
            from = c1; to = c2;
            if (mp.find(from) == mp.end()) mp[from] = cnt++;
            if (mp.find(to) == mp.end()) mp[to] = cnt++;

            vc.push_back(edge(mp[from], mp[to], w));
        }

        printf("%d\n", MST_Kruskal(vc, n));
        if (t) printf("\n");

        vc.clear();
        mp.clear();
    }
}
