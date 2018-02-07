#include<bits/stdc++.h>
using namespace std;

stack<int> stk;
int n, ndfn, comps;
vector<vector<int>> adjList;
vector<int> inStack, lowLink, dfn, comp, inDeg;

void Tarjan(int node) {
    lowLink[node] = dfn[node] = ndfn++, inStack[node] = 1;
    stk.push(node);
    for (int i = 0; i < adjList[node].size(); i++) {
        int ch = adjList[node][i];
        if (dfn[ch] == -1) {
            Tarjan(ch);
            lowLink[node] = min(lowLink[node], lowLink[ch]);
        } else if (inStack[ch]) {
            lowLink[node] = min(lowLink[node], dfn[ch]);
        }
    }
    if (lowLink[node] == dfn[node]) {
        int x = -1;
        comps++;
        while (x != node) {
            x = stk.top(); stk.pop(); inStack[x] = 0;
            comp[x] = comps-1;
        }
    }
}

void SCC() {
    inStack.clear(); inStack.resize(n);
    lowLink.clear(); lowLink.resize(n);
    dfn.clear(); dfn.resize(n, -1);
    ndfn = comps = 0;
    comp.clear(); comp.resize(n);
    for (int i = 0; i < n; i++) if (dfn[i] == -1) Tarjan(i);
}

int cntSources() {
    int cntSrc = comps;
    inDeg.clear(); inDeg.resize(comps);
    for (int i = 0; i < adjList.size(); i++) {
        for (int j = 0; j < adjList[i].size(); j++) {
            int k = adjList[i][j];
            if (comp[k] != comp[i])
                if (!(inDeg[comp[k]]++)) cntSrc--;
        }
    }
    return cntSrc;
}

int main() {
    int t, m, x, y;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &m);
        adjList.clear(); adjList.resize(n);
        while (m--) {
            scanf("%d %d", &x, &y);
            adjList[x-1].push_back(y-1);
        }
        SCC();
        printf("%d\n", cntSources());
    }
}
