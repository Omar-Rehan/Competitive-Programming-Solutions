#include<bits/stdc++.h>
using namespace std;

int clr[202];
vector<vector<int>> adjList;
bool BFS() {
    queue<pair<int,int>> q;
    q.push(make_pair(0,0));
    int sz = 1;
    pair<int,int> crnt;
    for (; !q.empty(); sz = q.size()) {
        while (sz--) {
            crnt = q.front();
            q.pop();
            for (int i = 0; i < adjList[crnt.first].size(); i++) {
                int child = adjList[crnt.first][i];
                if (clr[child] == -1) q.push(make_pair(child, clr[child] = !crnt.second));
                else if (clr[child] == crnt.second) return false;
            }
        }
    }
    return true;
}

int main() {
    int n, e, x, y;
    while (scanf("%d", &n) && n) {
        scanf("%d", &e);
        adjList.clear(); adjList.resize(n+2);
        memset(clr, -1, sizeof clr);
        while (e--) {
            scanf("%d %d", &x, &y);
            adjList[x].push_back(y);
            adjList[y].push_back(x);
        }
        if (BFS()) printf("BICOLORABLE.\n");
        else printf("NOT BICOLORABLE.\n");
    }
}
