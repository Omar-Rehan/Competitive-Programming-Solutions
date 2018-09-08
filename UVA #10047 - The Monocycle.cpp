#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second

pair<int, int> initPos, dest;
struct state {
    int x, y, dir, clr;
    state(int x, int y, int dir, int clr): x(x), y(y), dir(dir), clr(clr) {}

    bool reachedDestination() {
        return (x == dest.x && y == dest.y && !clr);
    }
};

char maze[30][30];
int n, m, testCase = 0, vis[30][30][5][6];
bool invalid(state pos) {
    return (pos.x < 0 || n <= pos.x || pos.y < 0 || m <= pos.y ||
            maze[pos.x][pos.y] == '#' ||
            vis[pos.x][pos.y][pos.dir][pos.clr] == testCase);
}

int BFS() {
    queue<state> q;
    q.push(state(initPos.x, initPos.y, 0, 0));

    state crnt = q.front();
    vis[crnt.x][crnt.y][crnt.dir][crnt.clr] = testCase;

    int dpth = 0, sz = 1;
    for (; !q.empty(); dpth++, sz = q.size()) {
        while (sz--) {
            crnt = q.front(); q.pop();

            // move forward
            state tmp = crnt;
            if (tmp.dir == 0) tmp.x--; // facing up
            if (tmp.dir == 1) tmp.y++; // facing right
            if (tmp.dir == 2) tmp.x++; // facing down
            if (tmp.dir == 3) tmp.y--; // facing left
            tmp.clr = (tmp.clr + 1) % 5;
            if (tmp.reachedDestination()) return dpth + 1;
            if (!invalid(tmp)) {
                q.push(tmp);
                vis[tmp.x][tmp.y][tmp.dir][tmp.clr] = testCase;
            }

            // turn right
            tmp = crnt;
            tmp.dir = (tmp.dir + 1) % 4;
            if (!invalid(tmp)) {
                q.push(tmp);
                vis[tmp.x][tmp.y][tmp.dir][tmp.clr] = testCase;
            }

            // turn left
            tmp = crnt;
            tmp.dir = (tmp.dir + 3) % 4;
            if (!invalid(tmp)) {
                q.push(tmp);
                vis[tmp.x][tmp.y][tmp.dir][tmp.clr] = testCase;
            }
        }
    }
    return -1;
}

int main() {
    string line;
    memset(vis, -1, sizeof vis);
    while (scanf("%d %d", &n, &m) && (n || m)) {
        scanf("\n");

        if (testCase) printf("\n");

        for (int i = 0; i < n; i++) {
            getline(cin, line);
            for (int j = 0; j < line.length(); j++) {
                maze[i][j] = line[j];

                if (maze[i][j] == 'S') initPos = pair<int,int>(i, j);
                if (maze[i][j] == 'T') dest = pair<int,int>(i, j);
            }
        }

        int secs = BFS();
        if (secs == -1) printf("Case #%d\ndestination not reachable\n", ++testCase);
        else printf("Case #%d\nminimum time = %d sec\n", ++testCase, secs);

    }
}
