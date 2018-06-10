#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-9;

struct point {
    double x, y;
    point() {x = y = 0.0;}
    point(double _x, double _y): x(_x), y(_y) {}
    bool operator < (point other) const {
        return x < other.x;
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

double dist(point p, point q) {
    return hypot(p.x - q.x, p.y - q.y);
}

int main() {
    int cases, n;
    double x, y;
    scanf("%d", &cases);
    while (cases--) {
        scanf("%d", &n);
        set<point> st;
        for (int i = 0; i < n; i++) {
            scanf("%lf %lf", &x, &y);
            st.insert(point(x, y));
        }
        auto it1 = st.end(), it2 = st.end();
        it1--; it2--; it2--;
        double res = 0.0, h = 0.0;
        while (true) {
            if (h <= (*it2).y && intersect((*it1), (*it2), point(0, h), point(30005, h))) {
                line l1 = pointsToLine((*it1), *(it2));
                line l2 = pointsToLine(point(0, h), point(30005, h));
                point p = findIntersect(l1, l2);
                h = (*it2).y;
                res += dist(p, (*it2));
            }
            it1--; it2--;
            if (it1 == st.begin() || it2 == st.begin()) break;
            it1--; it2--;
        }
        printf("%0.2lf\n", res);

    }
}
