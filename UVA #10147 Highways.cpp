#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    vector<int> ranks, parents;
    int forests;
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

struct point {
    int x, y;
    point() {x = y = 0;}
    point(int _x, int _y): x(_x), y(_y) {}
};

int distSquare(point p1, point p2) {
    return (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y);
}

vector<edge> edgeList, toBeBuilt;
vector<edge> Kruskal(int n) {
    UnionFind uf(n);
    vector<edge> edges;
    priority_queue<edge> q;
    
    // Build MST using existing highways but don't save the edges
    for (int i = 0; i < edgeList.size(); i++) q.push(edgeList[i]);
    while (!q.empty()) { 
        edge e = q.top(); q.pop();
        uf.union_sets(e.from, e.to);
    }
    
    // Complete the MST by building new roads and save the new edges
    for (int i = 0; i < toBeBuilt.size(); i++) q.push(toBeBuilt[i]);
    while (!q.empty()) { 
        edge e = q.top(); q.pop();
        if (uf.union_sets(e.from, e.to)) edges.push_back(e);
    }
    return edges;
}

int main() {
    int t, v, e, x, y;
    scanf("%d", &t);
    while (t--) {
        // Take in towns' positions
        scanf("%d", &v);
        point towns[v];
        for (int i = 0; i < v; i++) {
            scanf("%d %d", &x, &y);
            towns[i] = point(x, y);
        }
        
        // Take in built highways
        edgeList.clear();
        scanf("%d", &e);
        for (int i = 0; i < e; i++) {
            scanf("%d %d", &x, &y);
            x--; y--;
            edgeList.push_back(edge(x, y, distSquare(towns[x], towns[y])));
        }
        
        // Calculate all roads that can be built
        toBeBuilt.clear();
        for (int i = 0; i < v; i++) for (int j = 0; j < v; j++)
            toBeBuilt.push_back(edge(i, j, distSquare(towns[i], towns[j])));
            
        // Apply Kruskal Algorithm
        vector<edge> additionalRoads = Kruskal(v);
        
        // Print output
        if (additionalRoads.empty()) printf("No new highways need\n");
        else for (auto e : additionalRoads) printf("%d %d\n", e.from+1, e.to+1);
        if (t) printf("\n");
    }
}
