#include<bits/stdc++.h>
using namespace std;

int n, ndfn;
multimap<int,int> mp;
vector<vector<int>> adjList;
vector<int> dfn, lowLink, parent, articulationDeg;

void calcArticulation(int node) {
    lowLink[node] = dfn[node] = ndfn++;
    for (int i = 0; i < adjList[node].size(); i++) {
        int ch = adjList[node][i];
        if (dfn[ch] == -1) {
            parent[ch] = node;
            calcArticulation(ch);
            if (lowLink[ch] >= dfn[node]) articulationDeg[node]++;
            lowLink[node] = min(lowLink[node], lowLink[ch]);
        } else if (ch != parent[node]) {
            lowLink[node] = min(lowLink[node], dfn[ch]);
        }
    }
}

int main() {
    int m, x, y, idx;
    while (scanf("%d %d", &n, &m) && (n || m)) {
        idx = 0;
        adjList.clear(); adjList.resize(n);
        while (scanf("%d %d", &x, &y) && x != -1) {
            adjList[x].push_back(y);
            adjList[y].push_back(x);
        }

        // calculate pigeon values (find articulation degrees of all nodes)
        ndfn = 0;
        dfn.clear(); dfn.resize(n, -1);
        parent.clear(); parent.resize(n);
        lowLink.clear(); lowLink.resize(n);
        articulationDeg.clear(); articulationDeg.resize(n);
        calcArticulation(0);

        // put pigeon values into the multimap
        for (int i = 0; i < n; i++)
            mp.insert(make_pair(-articulationDeg[i] - (i != 0), i)); // the root doesn't need the ++

        // print required output
        for (auto e : mp) {
            if (idx++ == m) break;
            printf("%d %d\n", e.second, -e.first);
        }
        printf("\n");
        mp.clear();
    }
}
