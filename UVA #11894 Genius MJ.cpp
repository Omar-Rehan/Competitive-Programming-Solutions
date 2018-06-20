#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-9;
const double PI = 2 * acos(0.0);

struct point {
    double x, y;
    point() {x = y = 0.0;}
    point(double _x, double _y): x(_x), y(_y) {}
    bool operator < (point other) const {
        if (fabs(x - other.x) > EPS) return x < other.x;
        if (fabs(y - other.y) > EPS) return y < other.y;
        return false;
    }
};

point rotatePoint(point p, point q, int theta) { // Rotate 'p' wrt 'q' theta degrees
    double rad = theta * PI / 180;
    p.x -= q.x;
    p.y -= q.y;
    p = point(p.x * cos(rad) - p.y * sin(rad),
              p.x * sin(rad) + p.y * cos(rad));
    p.x += q.x;
    p.y += q.y;
    return p;
}

int main() {
    int t, n;
    double x, y, dx, dy;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        point plugs[n], sockets[n];
        for (int i = 0; i < n; i++) {
            scanf("%lf %lf", &x, &y);
            plugs[i] = point(x, y);
        }
        for (int i = 0; i < n; i++) {
            scanf("%lf %lf", &x, &y);
            sockets[i] = point(x, y);
        }
        sort(sockets, sockets + n);
        bool b = false;
        for (double ang = 0.0; ang < 359.0; ang += 90.0) {
            for (int i = 0; i < n; i++) {
                plugs[i] = rotatePoint(plugs[i], plugs[0], ang);
            }
            sort(plugs, plugs + n);
            dx = plugs[0].x - sockets[0].x;
            dy = plugs[0].y - sockets[0].y;
            bool tmp = true;
            for (int i = 0; i < n; i++) {
                tmp &= fabs((plugs[i].x - sockets[i].x) - dx) < EPS;
                tmp &= fabs((plugs[i].y - sockets[i].y) - dy) < EPS;
            }
            b |= tmp;
        }
        if (b) printf("MATCHED\n");
        else printf("NOT MATCHED\n");
    }
}
