#include <bits/stdc++.h>
using namespace std;

struct state {
    int x, y;
    state() {x = y = 0;}
    state(int x, int y): x(x), y(y) {}

    bool operator < (state other) const {
        if (x != other.x) return (x > other.x);
        return (y < other.y);
    }
};

char maze[100][100];
int n, m, cntSteps[100][100];
bool invalid(state p) {
    if (p.x < 1 || p.x > n || p.y < 1 || p.y > m) return true;
    if (maze[p.x][p.y] == 'X') return true;
    if (cntSteps[p.x][p.y] != -1) return true;

    return false;
}

set<state> st;
void BFS(state src) {
    queue<state> q;
    q.push(src);

    int dpth = 0, sz = 1;
    state crnt = q.front();
    for (; !q.empty(); dpth++, sz = q.size()) {
        while (sz--) {
            crnt = q.front(); q.pop();

            // Move Forward
            state tmp = state(crnt.x + 1, crnt.y);
            if (!dpth && !invalid(tmp)) {
                cntSteps[tmp.x][tmp.y] = dpth + 1;
                st.insert(tmp);
            }

            // Move Right
            tmp = state(crnt.x, crnt.y + 1);
            if (!dpth && !invalid(tmp)) {
                cntSteps[tmp.x][tmp.y] = dpth + 1;
                st.insert(tmp);
            }

            // Move Left
            tmp = state(crnt.x, crnt.y - 1);
            if (!dpth && !invalid(tmp)) {
                cntSteps[tmp.x][tmp.y] = dpth + 1;
                st.insert(tmp);
            }

            // Jump Forward
            tmp = state(crnt.x + 2, crnt.y);
            if (!invalid(tmp) && maze[tmp.x-1][tmp.y] == 'X') {
                cntSteps[tmp.x][tmp.y] = dpth + 1;
                st.insert(tmp);
                q.push(tmp);
            }

            // Jump Right
            tmp = state(crnt.x, crnt.y + 2);
            if (!invalid(tmp) && maze[tmp.x][tmp.y-1] == 'X') {
                cntSteps[tmp.x][tmp.y] = dpth + 1;
                st.insert(tmp);
                q.push(tmp);
            }

            // Jump Left
            tmp = state(crnt.x, crnt.y - 2);
            if (!invalid(tmp) && maze[tmp.x][tmp.y+1] == 'X') {
                cntSteps[tmp.x][tmp.y] = dpth + 1;
                st.insert(tmp);
                q.push(tmp);
            }

            // Jump Diagonal Right
            tmp = state(crnt.x + 2, crnt.y + 2);
            if (!invalid(tmp) && maze[tmp.x-1][tmp.y-1] == 'X') {
                cntSteps[tmp.x][tmp.y] = dpth + 1;
                st.insert(tmp);
                q.push(tmp);
            }

            // Jump Diagonal Left
            tmp = state(crnt.x + 2, crnt.y - 2);
            if (!invalid(tmp) && maze[tmp.x-1][tmp.y+1] == 'X') {
                cntSteps[tmp.x][tmp.y] = dpth + 1;
                st.insert(tmp);
                q.push(tmp);
            }
        }
    }

}


int main() {
    int x, y;
    bool firstCase = true;
    while (scanf("%d %d", &n, &m) != EOF) {
        if (!firstCase) printf("\n");
        firstCase = false;

        memset(maze, ' ', sizeof maze);
        memset(cntSteps, -1, sizeof cntSteps);

        for (int i = 0; i < 4*m; i++) {
            scanf("%d %d", &x, &y);
            maze[x][y] = 'X';
        }

        scanf("%d %d", &x, &y);
        BFS(state(x, y));

        for (auto e : st)
            printf("%d %d %d\n", e.x, e.y, cntSteps[e.x][e.y]);

        st.clear();
    }
}
