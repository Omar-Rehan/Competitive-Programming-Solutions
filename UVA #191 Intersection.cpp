#include <bits/stdc++.h>
using namespace std;

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
    int cases, x1, x2, y1, y2, l, r, t, b;
    scanf("%d", &cases);
    while (cases--) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        scanf("%d %d %d %d", &l, &t, &r, &b);
        point p1 = point(x1, y1);
        point p2 = point(x2, y2);
        point c1 = point(l, t);
        point c2 = point(l, b);
        point c3 = point(r, b);
        point c4 = point(r, t);
        bool bl = false;
        bl |= intersect(p1, p2, c1, c2);
        bl |= intersect(p1, p2, c2, c3);
        bl |= intersect(p1, p2, c3, c4);
        bl |= intersect(p1, p2, c4, c1);
        // The corners are not necessarily top-left & bottom-right
        bl |= (p1.x <= max(r, l) && p1.x >= min(r, l) && p1.y <= max(t, b) && p1.y >= min(t, b));
        if (bl) printf("T\n");
        else printf("F\n");
    }
}
