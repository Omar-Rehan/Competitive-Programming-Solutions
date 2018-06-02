#include <bits/stdc++.h>
using namespace std;

struct player {
    double x, y, v;
    player(){x = y = v = 0;}
    player(double _x, double _y, double _v): x(_x), y(_y), v(_v) {}
};

player arr[25];
bool catchBall(player p, double t, double x, double y) {
    double d = sqrt((p.x-x)*(p.x-x) + (p.y-y)*(p.y-y));
    double tt = d / p.v;
    return tt <= t;
}

int main() {
    int n, b, x, y, v;
    scanf("PLAYERS=%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &x, &y, &v);
        arr[i] = player(x, y, v);
    }
    scanf("\nBALLS=%d", &b);
    int z0, z1, z2, x0, x1, y0, y1;
    for (int i = 1; i <= b; i++) {
        scanf("%d %d %d %d %d %d %d", &z2, &z1, &z0, &x1, &x0, &y1, &y0);
        int t = (int)ceil((-z1 - sqrt(z1*z1 - 4*z2*z0)) / (2 * z2));
        x = x1 * t + x0;
        y = y1 * t + y0;
        if (x < 0 || y < 0) {
            printf("Ball %d was foul at (%d,%d)\n", i, x, y);
        } else {
            bool caught = false;
            for (int j = 0; j < n && !caught; j++) {
                if (catchBall(arr[j], t, x, y)) caught = true;
            }
            if (caught) printf("Ball %d was caught at (%d,%d)\n", i, x, y);
            else printf("Ball %d was safe at (%d,%d)\n", i, x, y);
        }
    }
}
