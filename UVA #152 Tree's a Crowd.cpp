#include <bits/stdc++.h>
using namespace std;
const double INF = (1 << 30);
const double EPS = 1e-9;

struct point {
    int x, y, z;
    point(){x = y = z = 0.0;}
    point(int _x, int _y, int _z): x(_x), y(_y), z(_z) {}
};

point arr[5005];
int distSq(point p1, point p2) {
    return (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y) + (p1.z - p2.z)*(p1.z - p2.z);
}

int main() {
    int cnt = 0, x, y, z;
    while (scanf("%d %d %d", &x, &y, &z) && (x || y || z)) {
        arr[cnt] = point(x, y, z);
        cnt++;
    }
    int res[10] = {0};
    for (int i = 0; i < cnt; i++) {
        int tmp = INF;
        for (int j = 0; j < cnt; j++) {
            if (i == j) continue;
            tmp = min(tmp, distSq(arr[i], arr[j]));
        }
        int idx = (int)ceil(sqrt(tmp) + EPS) - 1;
        if (idx < 10) res[idx]++;
    }
    for (int i = 0; i < 10; i++) printf("%4d", res[i]);
    printf("\n");
}
