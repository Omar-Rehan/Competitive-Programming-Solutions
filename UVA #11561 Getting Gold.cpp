#include<bits/stdc++.h>
using namespace std;

int n, m, sx, sy;
bool vis[52][52];
char grid[52][52];
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

bool valid(int x, int y) {
    if (x < 1 || y < 1 || x > n || y > m || grid[x][y] == '#' || vis[x][y]) return false;
    return true;
}

bool danger(int x, int y) {
    for (int i = 0; i < 4; i++) {
        if (x+dx[i] < 1 || y+dy[i] < 1 || x+dx[i] > n || y+dy[i] > m) continue;
        if (grid[x+dx[i]][y+dy[i]] == 'T') return true;
    }
    return false;
}

int BFS() {
    queue<pair<int,int>> q;
    q.push(make_pair(sx, sy));
    vis[sx][sy] = true;
    int sz = 1, res = 0;
    pair<int,int> crnt;
    for (; !q.empty(); sz = q.size()) {
        while (sz--) {
            crnt = q.front();
            q.pop();
            res += (grid[crnt.first][crnt.second] == 'G');
            if (danger(crnt.first, crnt.second)) continue;
            for (int i = 0; i < 4; i++) {
                if (valid(crnt.first+dx[i], crnt.second+dy[i])) {
                    q.push(make_pair(crnt.first+dx[i], crnt.second+dy[i]));
                    vis[crnt.first+dx[i]][crnt.second+dy[i]] = true;
                }
            }
        }
    }
    return res;
}

int main() {
    while (scanf("%d %d", &m, &n) != EOF) {
        memset(vis, false, sizeof vis);
        for (int i = 1; i <= n; i++) {
            cin.ignore();
            for (int j = 1; j <= m; j++) {
                scanf("%c", &grid[i][j]);
                if (grid[i][j] == 'P')
                    sx = i, sy = j;
            }
        }
        printf("%d\n", BFS());
    }
}
