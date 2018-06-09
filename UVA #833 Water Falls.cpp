#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-9;

struct point {
    double x, y;
    point() {x = y = 0;}
    point(double _x, double _y): x(_x), y(_y) {}
    bool operator < (point other) const {
        return y < other.y;
    }
    bool operator != (point other) const {
        return fabs(y - other.y) > EPS;
    }
};

struct line {
    double a, b, c;
};

line pointsToLine(point p1, point p2) {
    line l;
    if (fabs(p1.x - p2.x) < EPS) {
        l.a = 1.0; l.b = 0.0; l.c = -p1.x;
    } else {
        l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
        l.b = 1.0;
        l.c = -(double)(l.a * p1.x) - p1.y;
    }
    return l;
}

point findIntersect(line l1, line l2) {
    point p;
    p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
    if (fabs(l1.b) > EPS) p.y = -(l1.a * p.x + l1.c);
    else                  p.y = -(l2.a * p.x + l2.c);
    return p;
}

bool onSegment(point p, point a, point b) {
    if (p.x <= max(a.x, b.x) && p.x >= min(a.x, b.x) &&
        p.y <= max(a.y, b.y) && p.y >= min(a.y, b.y)  )
        return true;
    return false;
}

int orientation(point a, point b, point c) {
    double val = (b.y - a.y)*(c.x - b.x) - (b.x - a.x)*(c.y - b.y);
    if (fabs(val) < EPS) return 0; // collinear
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

int n;
point arr[100][2];
point findSpot(point p) {
    if (!p.y) return p;
    int idx = n;
    point r = point(p.x, 0.0);
    line l1 = pointsToLine(p, r);
    for (int i = 0; i < n; i++) {
        if (intersect(p, r, arr[i][0], arr[i][1])) {
            line l2 = pointsToLine(arr[i][0], arr[i][1]);
            point tmp = findIntersect(l1, l2);
            if (tmp != p && r < tmp) {r = tmp; idx = i;}
        }
    }
    if (idx == n) return r;
    return findSpot(min(arr[idx][0], arr[idx][1]));
}

int main() {
    int cases, m, x1, x2, y1, y2;
    scanf("%d", &cases);
    while (cases--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            arr[i][0] = point(x1, y1);
            arr[i][1] = point(x2, y2);
        }

        scanf("%d", &m);
        while (m--) {
            scanf("%d %d", &x1, &y1);
            point p = findSpot(point(x1, y1));
            printf("%d\n", (int)round(p.x));
        }
        if (cases) printf("\n");
    }
}
