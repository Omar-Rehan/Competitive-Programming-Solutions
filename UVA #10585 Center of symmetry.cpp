#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-9;

struct point {
    double x, y;
    point(){x = y = 0;}
    point(double _x, double _y): x(_x), y(_y) {}
    bool operator < (point other) const {
        if (fabs(x - other.x) > EPS) return x < other.x;
        return y < other.y;
    }
    bool operator == (point other) const {
        return (fabs(x - other.x) < EPS && fabs(y - other.y) < EPS);
    }
};

int main() {
    int t, n, x, y;
    double cx, cy;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        set<point> st;
        cx = cy = 0.0;
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &x, &y);
            st.insert(point(x, y));
            cx += x; cy += y;
        }
        point c = point(cx / n, cy / n);
        bool sym = true;
        for (auto p : st) {
            if (st.find(point(2*c.x - p.x, 2*c.y - p.y)) == st.end()) {
                sym = false;
                break;
            }
        }
        if (sym) printf("yes\n");
        else printf("no\n");
    }
}
