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

int calc(string a, string b) {
    int ret = 0;
    for (int i = 0; i < 4; i++)
        ret += min(abs(a[i] - b[i]), 10 - abs(a[i] - b[i]));
    return ret;
}

int main() {
    int t, n;
    char c[8];
    string str;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        
        string arr[n+1];
        arr[0] = "0000";
        for (int i = 1; i <= n; i++) {
            scanf("%s", &c);
            str = c;
            arr[i] = str;
        }

        vector<edge> vc;
        int baseWeight = INF, idx = -1;
        for (int i = 1; i <= n; i++) { // find the smallest-weighted edge from "0000"
            if (baseWeight > calc(arr[0], arr[i])) {
                idx = i;
                baseWeight = calc(arr[0],arr[i]);
            }
        }
        
        for (int i = 0; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                if (!i && j != idx) // We cannot jump to "0000"
                    vc.push_back(edge(0, idx, calc(arr[i], arr[j]) + baseWeight));
                else 
                    vc.push_back(edge(i, j, calc(arr[i], arr[j])));
            }
        }

        printf("%d\n", MST_Kruskal(vc, n+1));
    }
}
