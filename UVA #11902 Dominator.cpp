#include<bits/stdc++.h>
using namespace std;

int n, dmnt;
bool res[102][102];
vector<vector<int>> adjList;

void DFS(int node) {
    if (node == dmnt) return;
    res[dmnt][node] = true;
    for (int i = 0; i < adjList[node].size(); i++)
        if (!res[dmnt][adjList[node][i]]) DFS(adjList[node][i]);
}

void formatOutput() {
    string ln;
    for (int i = 0; i < 2*n+1; i++) ln += (!i || i == 2*n ? '+' : '-');
    cout << ln << endl;
    for (int i = 0; i < n; i++) {
        printf("|");
        for (int j = 0; j < n; j++)
            printf("%c|", (!res[n][i] || !res[n][j] ? 'N' : (res[i][j] ? 'N' : 'Y')));
        cout << endl << ln << endl;
    }
}

int main() {
    int t, x;
    scanf("%d", &t);
    for (int q = 1; q <= t; q++) {
        scanf("%d", &n);
        adjList.clear();
        adjList.resize(n+2);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                scanf("%d", &x);
                if (x) adjList[i].push_back(j);
            }
        printf("Case %d:\n", q);
        memset(res, false, sizeof res);
        dmnt = n;
        DFS(0);
        for (int i = 0; i < n; i++) {
            if (!res[n][i]) continue;
            dmnt = i;
            DFS(0);
        }
        formatOutput();
    }
}
