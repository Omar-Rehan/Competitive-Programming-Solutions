#include <bits/stdc++.h>
using namespace std;
const int INF = (1 << 28);

struct point {
    int x, y;
    point(int x, int y): x(x), y(y) {}
};

struct edge {
    point from, to;
    int w, steps;
    edge(point f, point t, int w, int s): from(f), to(t), w(w), steps(s) {}
    bool operator < (edge e) const {return w > e.w;}
};

int n, grid[30][30];
bool outOfBounds(point p) {
    return (p.x < 0 || p.x >= n || p.y < 0 || p.y >= n);
}

int dist[7][30][30][30];
void fillDist(int val) {
    for (int i = 0; i < 7; i++)
        for (int j = 0; j < 30; j++)
            for (int k = 0; k < 30; k++)
                for (int m = 0; m < 30; m++) dist[i][j][k][m] = val;
}

int t, dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
void Dijkstra(int frnd, point initPos) {
    dist[frnd][initPos.x][initPos.y][0] = 0;

    priority_queue<edge> pq;
    pq.push(edge(point(-1, -1), initPos, 0, 0));

    while (!pq.empty()) {
        edge e = pq.top(); pq.pop();
        if (e.w > dist[frnd][e.to.x][e.to.y][e.steps]) continue;

        for (int i = 0; i < 4; i++) {
            edge ne = edge(e.to, point(e.to.x + dx[i], e.to.y + dy[i]), grid[e.to.x][e.to.y], e.steps + 1);
            if (!outOfBounds(ne.to) && dist[frnd][ne.to.x][ne.to.y][ne.steps] > dist[frnd][ne.from.x][ne.from.y][ne.steps-1] + ne.w) {
                ne.w = dist[frnd][ne.to.x][ne.to.y][ne.steps] = dist[frnd][ne.from.x][ne.from.y][ne.steps-1] + ne.w;
                if (ne.steps < t) pq.push(ne);
            }
        }
    }
}

int main() {
    int f, x, y, testCase = 0;
    while (scanf("%d %d %d", &n, &f, &t) && (n || f || t)) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) scanf("%d", &grid[i][j]);

        fillDist(INF);
        int arr[f][2];
        for (int frnd = 0; frnd < f; frnd++) {
            scanf("%d %d", &x, &y);
            Dijkstra(frnd, point(x, y));
            arr[frnd][0] = x; arr[frnd][1] = y;
        }

        int row = -1, col = -1, cost = INF;
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                int sum = 0;
                for (int frnd = 0; frnd < f; frnd++) {
                    int tmp = INF;
                    for (int s = 0; s <= t; s++) tmp = min(tmp, dist[frnd][r][c][s]);
                    sum += tmp;
                }
                
                if (sum < cost) {
                    cost = sum;
                    row = r, col = c;
                }
            }
        }

        if (cost == INF) printf("Case #%d: Impossible.\n", ++testCase);
        else printf("Case #%d: Selected city (%d,%d) with minimum cost %d.\n", ++testCase, row, col, cost);
    }
}
