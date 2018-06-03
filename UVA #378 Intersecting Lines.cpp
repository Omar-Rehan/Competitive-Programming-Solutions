#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-9;

struct point {
    double x, y;
    point(){x = y = 0;}
    point(double _x, double _y): x(_x), y(_y) {}
};

struct line {double a, b, c;};
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

bool areParallel(line l1, line l2) {
    return (fabs(l1.a - l2.a) < EPS && fabs(l1.b - l2.b) < EPS);
}
bool areSame(line l1, line l2) {
    return (areParallel(l1, l2) && fabs(l1.c - l2.c) < EPS);
}
point intersect(line l1, line l2) {
    point p;
    p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
    if (fabs(l1.b) > EPS) p.y = -(l1.a * p.x + l1.c);
    else p.y = -(l2.a * p.x + l2.c);
    return p;
}

int main() {
    int n, x1, x2, x3, x4, y1, y2, y3, y4;
    scanf("%d", &n);
    printf("INTERSECTING LINES OUTPUT\n");
    while (n--) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        scanf("%d %d %d %d", &x3, &y3, &x4, &y4);
        line l1 = pointsToLine(point(x1, y1), point(x2, y2));
        line l2 = pointsToLine(point(x3, y3), point(x4, y4));
        if (areSame(l1, l2)) printf("LINE\n");
        else if (areParallel(l1, l2)) printf("NONE\n");
        else {
            point p = intersect(l1, l2);
            printf("POINT %0.2lf %0.2lf\n", p.x, p.y);
        }
    }
    printf("END OF OUTPUT\n");
}
