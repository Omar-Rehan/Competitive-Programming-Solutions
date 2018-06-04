#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-9;

struct point {
    double x, y;
    point() {x = y = 0;}
    point(double _x, double _y): x(_x), y(_y) {}
};

struct vec {
    double x, y;
    vec(double _x, double _y): x(_x), y(_y) {}
};
vec toVector(point a, point b) {return vec(b.x - a.x, b.y - a.y);}
double crossProd(vec a, vec b) {return a.x * b.y - a.y * b.x;}

bool CCW(point p, point q, point r) {
    return crossProd(toVector(p, q), toVector(p, r)) > 0;
}

int n;
point arr[105];
bool check(int a, int b) {
    int ret = 0;
    point p = point(0.0, 0.0);
    point q = point(1.0, -1.0 * a / b);
    for (int i = 0; i < n; i++) {
        // Cherry is on the line
        double y = -1.0 * a * arr[i].x / b;
        if (fabs(y - arr[i].y) < EPS) return false;
        // Which side the cherry is on
        ret += (CCW(p, q, arr[i]) ? 1 : -1);
    }
    return !ret;
}

int main() {
    double x, y;
    while (scanf("%d", &n) && n) {
        n <<= 1;
        for (int i = 0; i < n; i++) {
            scanf("%lf %lf", &x, &y);
            arr[i] = point(x, y);
        }
        int resA, resB;
        bool found = false;
        for (int A = -500; A <= 500 && !found; A++) {
            for (int B = -500; B <= 500 && !found; B++) {
                if (!A || !B) continue;
                if (check(A, B)) {
                    resA = A;
                    resB = B;
                    found = true;
                }
            }
        }
        printf("%d %d\n", resA, resB);
    }
}
