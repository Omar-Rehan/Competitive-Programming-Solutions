#include<bits/stdc++.h>
using namespace std;
#define n first
#define e second

bool vis[302], taken[1002];
vector<vector<pair<int,int>>> adjList;

void DFS(int node) {
    vis[node] = 1;
    pair<int,int> c1 = adjList[node][0];
    pair<int,int> c2 = adjList[node][1];
    pair<int,int> c3 = adjList[node][2];
    if (!taken[c1.e] && !taken[c2.e] && !taken[c3.e])
        taken[c1.e] = taken[c2.e] = taken[c3.e] = 1;
    for (int i = 0; i < adjList[node].size(); i++) {
        pair<int,int> ch = adjList[node][i];
        if (!vis[ch.n]) DFS(ch.n);
    }
}

int main() {
    int n, m, x, y;
    while (scanf("%d", &n) && n) {
        m = 0;
        adjList.clear(); adjList.resize(n);
        while (scanf("%d %d", &x, &y) && (x && y)) {
            adjList[x-1].push_back(make_pair(y-1,m));
            adjList[y-1].push_back(make_pair(x-1,m));
            m++;
        }
        memset(vis, 0, sizeof vis);
        memset(taken, 0, sizeof taken);
        DFS(0);
        if (m%3 || accumulate(taken,taken+n,0) != n) printf("NO\n");
        else printf("YES\n");
    }
}
