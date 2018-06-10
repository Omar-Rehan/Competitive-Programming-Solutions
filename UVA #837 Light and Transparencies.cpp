#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-9;
const double INF = (1 << 30);

struct point {
    double x, y;
    point() {x = y = 0;}
    point(double _x, double _y): x(_x), y(_y) {}
};

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

int main() {
    int cases, n;
    double x1, x2, y1, y2, t;
    scanf("%d", &cases);
    while (cases--) {
        scanf("%d", &n);
        double tr[n];
        point arr[n][2];
        set<double> st;
        for (int i = 0; i < n; i++) {
            scanf("%lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &tr[i]);
            arr[i][0] = point(x1, y1);
            arr[i][1] = point(x2, y2);
            st.insert(x1);
            st.insert(x2);
        }
        set<double>::iterator it1 = st.begin();
        set<double>::iterator it2 = st.begin();
        it2++;
        printf("%d\n-inf %0.3lf 1.000\n", st.size()+1, (*it1));
        while (it2 != st.end()) {
            t = 1.0;
            point s = point(((*it1) + (*it2)) / 2, INF);
            point r = point(((*it1) + (*it2)) / 2, 0.0);
            for (int i = 0; i < n; i++)
                if (intersect(s, r, arr[i][0], arr[i][1])) t *= tr[i];
            printf("%0.3lf %0.3lf %0.3lf\n", (*it1), (*it2), t);
            it1++; it2++;
        }
        printf("%0.3lf +inf 1.000\n", (*it1));

        if (cases) printf("\n");
    }
}
