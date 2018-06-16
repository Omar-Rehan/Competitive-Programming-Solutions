#include <bits/stdc++.h>
using namespace std;

struct point {
    double x, y;
    point() {x = y = 0.0;}
    point(double _x, double _y): x(_x), y(_y) {}
};

bool onSegment(point p, point a, point b) {
    return (p.x <= max(a.x, b.x) && p.x >= min(a.x, b.x) &&
            p.y <= max(a.y, b.y) && p.y >= min(a.y, b.y));
}

int orientation(point p, point a, point b) {
    int val = (p.y - a.y) * (b.x - p.x) - (p.x - a.x) * (b.y - p.y);
    if (!val) return 0; // collinear
    return (val > 0 ? 1 : 2); // CW : CCW
}

bool intersect(point a1, point b1, point a2, point b2) {
    int o1 = orientation(b1, a1, a2);
    int o2 = orientation(b1, a1, b2);
    int o3 = orientation(b2, a2, a1);
    int o4 = orientation(b2, a2, b1);
    if (o1 != o2 && o3 != o4) return true; // General case
    if (!o1 && onSegment(a2, a1, b1)) return true;
    if (!o2 && onSegment(b2, a1, b1)) return true;
    if (!o3 && onSegment(a1, a2, b2)) return true;
    if (!o4 && onSegment(b1, a2, b2)) return true;
    return false;
}

int main() {
    int n;
    double x1, x2, y1, y2;
    while (scanf("%d", &n) && n) {
        point arr[n][2];
        for (int i = 0; i < n; i++) {
            scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
            arr[i][0] = point(x1, y1);
            arr[i][1] = point(x2, y2);
        }
        printf("Top sticks: ");
        for (int i = 0; i < n-1; i++) {
            bool top = true;
            for (int j = i+1; j < n && top; j++) {
                if (intersect(arr[i][0], arr[i][1], arr[j][0], arr[j][1]))
                    top = false;
            }
            if (top) printf("%d, ", i+1);
        }
        printf("%d.\n", n);
    }
}
