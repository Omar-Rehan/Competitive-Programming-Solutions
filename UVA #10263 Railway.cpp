#include <bits/stdc++.h>
using namespace std;
const double INF = (1 << 30);
const double EPS = 1e-9;

struct point {
    double x, y;
    point(){x = y = 0;}
    point(double _x, double _y): x(_x), y(_y) {}
};

struct vec {
    double x, y;
    vec(double _x, double _y): x(_x), y(_y) {}
};

point cc;
double dist(point a, point b) {return hypot(a.x - b.x, a.y - b.y);}
vec toVector(point a, point b) {return vec(b.x - a.x, b.y - a.y);}
vec scale(vec v, double s) {return vec(v.x * s, v.y * s);}
point translate(point p, vec v) {return point(p.x + v.x, p.y + v.y);}
double dotProd(vec a, vec b) {return a.x * b.x + a.y * b.y;}
double norm_sq(vec v) {return v.x * v.x + v.y * v.y;}

double distToLine(point p, point a, point b) {
    vec ap = toVector(a, p), ab = toVector(a, b);
    double u = dotProd(ap, ab) / norm_sq(ab);
    cc = translate(a, scale(ab, u));
    return dist(p, cc);
}

double distToSegment(point p, point a, point b) {
    vec ap = toVector(a, p), ab = toVector(a, b);
    double u = dotProd(ap, ab) / norm_sq(ab);
    if (u < 0.0) {cc = a; return dist(p, a);}
    if (u > 1.0) {cc = b; return dist(p, b);}
    return distToLine(p, a, b);
}

int main() {
    int n;
    double x, y, len;
    point p0, p1, p2, m, res;
    while (scanf("%lf %lf %d", &x, &y, &n) != EOF) {
        len = INF;
        m = point(x, y);
        scanf("%lf %lf", &x, &y);
        p0 = p1 = point(x, y);
        while (n--) {
            p2 = p1;
            scanf("%lf %lf", &x, &y);
            p1 = point(x, y);
            double d = distToSegment(m, p1, p2);
            if (d < len) {
                len = d;
                res = cc;
            }
        }
        printf("%0.4lf\n%0.4lf\n", res.x, res.y);
    }
}
