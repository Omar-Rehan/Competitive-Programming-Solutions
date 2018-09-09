#include <bits/stdc++.h>
using namespace std;
const int MOD = 20437;

struct point {
    int x, y;
    point() {x = y = 0;}
    point(int x, int y): x(x), y(y) {}
};

char maze[12][12];
int n, t = 0, vis[12][12];
bool invalid(point p) {
    if (p.x < 1 || p.x > n || p.y < 1 || p.y > n) return true;
    if (maze[p.x][p.y] == '#') return true;
    if (vis[p.x][p.y] == t) return true;
    return false;
}

int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
pair<int,int> BFS(point src, char trgt) {
    int cnt = 0, shortestPath = 60;
    queue<point> q;
    q.push(src);

    int dpth = 0, sz = 1;
    point crnt = q.front();
    for (; !q.empty() && dpth <= shortestPath; dpth++, sz = q.size()) {
        while (sz--) {
            crnt = q.front(); q.pop();
            if (maze[crnt.x][crnt.y] == trgt) {
                shortestPath = dpth;
                cnt++;
                cnt %= MOD;
            }
            vis[crnt.x][crnt.y] = t;

            for (int i = 0; i < 4; i++) {
                point tmp = point(crnt.x + dx[i], crnt.y + dy[i]);
                if (!invalid(tmp) && (!isalpha(maze[tmp.x][tmp.y]) || maze[tmp.x][tmp.y] <= trgt)) q.push(tmp);
            }
        }
    }
    if (shortestPath == 60) return pair<int,int>(-1, 0);
    return pair<int,int>(shortestPath, cnt);
}

int main() {
    int testCase = 0;
    memset(vis, -1, sizeof vis);
    while (scanf("%d", &n) && n) {
        map<char,point> mp;
        for (int i = 1; i <= n; i++) {
            scanf("\n");
            for (int j = 1; j <= n; j++) {
                scanf("%c", &maze[i][j]);
                if (isalpha(maze[i][j]))
                    mp[maze[i][j]] = point(i, j);
            }
        }
        
        bool noAns = false;
        int shortestPath = 0, cnt = 1;
        for (char cc = 'A'; cc < 'A' + mp.size() - 1; cc++) {
            t++;
            pair<int,int> res = BFS(mp[cc], cc+1);
            if (res.first == -1) {
                noAns = true;
                break;
            }
            shortestPath += res.first;
            cnt *= res.second;
            cnt %= MOD;
        }
        
        if (noAns) printf("Case %d: Impossible\n", ++testCase);
        else printf("Case %d: %d %d\n", ++testCase, shortestPath, cnt);
    }
}
