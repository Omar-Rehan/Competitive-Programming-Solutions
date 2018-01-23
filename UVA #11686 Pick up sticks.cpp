#include<bits/stdc++.h>
using namespace std;

int cnt[1000002];
bool vis[1000002];
vector<int> res;
vector<vector<int>> adjList;
void BFS(int root) {
    queue<int> q;
    q.push(root);
    int sz = 1;
    int crnt;
    for (; !q.empty(); sz = q.size()) {
        while (sz--) {
            crnt = q.front();
            q.pop();
            for (int i = 0; i < adjList[crnt].size(); i++) {
                int child = adjList[crnt][i];
                cnt[child]--;
                if (!cnt[child]) {
                    res.push_back(child);
                    q.push(child);
                    vis[child] = true;
                }
            }
        }
    }
}

int main() {
    int n, e, x, y;
    while (scanf("%d %d", &n, &e) && (n || e)) {
        res.clear();
        adjList.clear(); adjList.resize(n+2);
        memset(vis, false, sizeof vis);
        memset(cnt, 0, sizeof cnt);
        while (e--) {
            scanf("%d %d", &x, &y);
            adjList[x].push_back(y);
            cnt[y]++;
        }
        for (int i = 1; i <= n; i++) if (!cnt[i] && !vis[i]) {res.push_back(i); BFS(i);}
        if (res.size() != n) printf("IMPOSSIBLE\n");
        else for (auto r : res) printf("%d\n", r);
    }
}
