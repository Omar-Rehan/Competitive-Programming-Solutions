#include <bits/stdc++.h>
using namespace std;
const double PI = 2 * acos(0.0);

struct point {
    double x, y;
    point() {x = y = 0.0;}
    point(double _x, double _y): x(_x), y(_y) {}
};

double dist(point a, point b) {
    return hypot(a.x - b.x, a.y - b.y);
}

point rotatePoint(point p, double t, double T) {
    while (T > t) T -= t;
    double theta = T / t * 360.0;
    double rad = theta * PI / 180.0;
    return point(p.x * cos(rad) - p.y * sin(rad),
                 p.x * sin(rad) - p.y * cos(rad));
}

int main() {
    int n;
    double r, t, T;
    while (scanf("%d %lf", &n, &T) != EOF) {
        point tmp;
        while (n--) {
            scanf("%lf %lf", &r, &t);
            point p = rotatePoint(point(r, 0), t, T);
            p.x += tmp.x;
            p.y += tmp.y;
            printf("%0.4lf", dist(p, point(0, 0)));
            if (n) printf(" ");
            tmp = p;
        }
        printf("\n");
    }
}
