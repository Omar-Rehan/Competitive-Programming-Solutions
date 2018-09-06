#include <bits/stdc++.h>
using namespace std;
const int INF = (1 << 31) - 1;

vector<vector<int>> adjList;
vector<int> importantStations;
int BFS(int root) {
    vector<int> dist(adjList.size(), INF);
    queue<int> q;
    q.push(root), dist[root] = 0;

    int dpth = 0, crnt = root, sz = 1;
    for (; !q.empty(); dpth++, sz = q.size()) {
        while (sz--) {
            crnt = q.front();
            q.pop();
            for (int i = 0; i < adjList[crnt].size(); i++) {
                if (dist[adjList[crnt][i]] == INF) {
                    q.push(adjList[crnt][i]);
                    dist[adjList[crnt][i]] = dpth + 1;
                }
            }
        }
    }

    int ret = 0;
    for (auto s : importantStations)
        if (s != root) ret += dist[s];
    return ret;
}

int main() {
    int t, n, lines, x;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &lines);
        int vis[n] = {0};
        importantStations.clear();
        adjList.clear(); adjList.resize(n);

        for (int i = 0; i < lines; i++) {
            vector<int> tmp;
            while (scanf("%d", &x) && x) tmp.push_back(x-1), vis[x-1]++;

            for (int i = 0; i < tmp.size(); i++) {
                if (i) adjList[tmp[i]].push_back(tmp[i-1]);
                if (i+1 < tmp.size()) adjList[tmp[i]].push_back(tmp[i+1]);
            }
        }

        for (int i = 0; i < n; i++)
            if (vis[i] > 1) importantStations.push_back(i);

        int station = -1, sum = INF;
        for (auto s : importantStations) {
            int tmp = BFS(s);
            if (tmp < sum) {
                station = s;
                sum = tmp;
            }
        }

        printf("Krochanska is in: %d\n", station+1);
    }
}
