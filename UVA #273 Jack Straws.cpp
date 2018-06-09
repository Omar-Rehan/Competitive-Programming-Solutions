#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    vector<int> parent;
    UnionFind(int n) {
        parent = vector<int>(n+1);
        for (int i = 1; i <= n; i++) parent[i] = i;
    }
    int findSet(int x) {
        if (x == parent[x]) return x;
        return parent[x] = findSet(parent[x]);
    }
    void Link(int x, int y) {
        parent[x] = y;
    }
    void unionSets(int x, int y) {
        x = findSet(x);
        y = findSet(y);
        if (x != y) Link(x, y);
    }
    bool sameSet(int x, int y) {return findSet(x) == findSet(y);}
};

struct point {
    int x, y;
    point() {x = y = 0;}
    point(int _x, int _y): x(_x), y(_y) {}
};

bool onSegment(point p, point a, point b) {
    if (p.x <= max(a.x, b.x) && p.x >= min(a.x, b.x) &&
        p.y <= max(a.y, b.y) && p.y >= min(a.y, b.y)  )
        return true;
    return false;
}

int orientation(point a, point b, point c) {
    int val = (b.y - a.y)*(c.x - b.x) - (b.x - a.x)*(c.y - b.y);
    if (!val) return 0; // collinear
    return (val > 0 ? 1 : 2); // CW : CCW
}

bool intersect(point a1, point b1, point a2, point b2) {
    int or1 = orientation(a1, b1, a2);
    int or2 = orientation(a1, b1, b2);
    int or3 = orientation(a2, b2, a1);
    int or4 = orientation(a2, b2, b1);

    if (or1 != or2 && or3 != or4) return true;
    if (!or1 && onSegment(a2, a1, b1)) return true;
    if (!or2 && onSegment(b2, a1, b1)) return true;
    if (!or3 && onSegment(a1, a2, b2)) return true;
    if (!or4 && onSegment(b1, a2, b2)) return true;
    return false;
}

int main() {
    int cases, n, x1, x2, y1, y2;
    scanf("%d", &cases);
    while (cases--) {
        scanf("%d", &n);
        point arr[n+1][2];
        for (int i = 1; i <= n; i++) {
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            arr[i][0] = point(x1, y1);
            arr[i][1] = point(x2, y2);
        }
        UnionFind uf(n);
        for (int i = 1; i < n; i++) {
            for (int j = i+1; j <= n; j++) {
                if (intersect(arr[i][0], arr[i][1], arr[j][0], arr[j][1])) 
                    uf.unionSets(i, j);
            }
        }
        while (scanf("%d %d", &x1, &x2) && (x1 || x2)) {
            if (uf.sameSet(x1, x2)) printf("CONNECTED\n");
            else printf("NOT CONNECTED\n");
        }
        if (cases) printf("\n");
    }
}
