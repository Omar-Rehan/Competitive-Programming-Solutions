#include<bits/stdc++.h>
using namespace std;

int ndfn;
stack<int> stk;
vector<int> inStack, lowLink, dfn;
vector<vector<int>> adjList, comps;
void tarjan(int node) {
    lowLink[node] = dfn[node] = ndfn++, inStack[node] = 1;
    stk.push(node);
    for (int i = 0; i < adjList[node].size(); i++) {
        int ch = adjList[node][i];
        if (dfn[ch] == -1) {
            tarjan(ch);
            lowLink[node] = min(lowLink[node], lowLink[ch]);
        } else if (inStack[ch]) {
            lowLink[node] = min(lowLink[node], dfn[ch]);
        }
    }
    if (lowLink[node] == dfn[node]) {
        comps.push_back(vector<int>());
        int x = -1;
        while (x != node) {
            x = stk.top(), stk.pop(), inStack[x] = 0;
            comps.back().push_back(x);
        }
    }
}

void SCC() {
	int n = adjList.size();
	inStack.clear(); inStack.resize(n);
	lowLink.clear(); lowLink.resize(n);
	dfn.clear(); dfn.resize(n, -1);
	ndfn = 0;
	comps.clear();
	for (int i = 1; i <= n; i++) if (dfn[i] == -1) tarjan(i);
}

int main() {
    int n, m, a, b, c;
    while (scanf("%d %d", &n, &m) && (n || m)) {
        adjList.clear(); adjList.resize(n+1);
        for (int i = 0; i < m; i++) {
            scanf("%d %d %d", &a, &b, &c);
            adjList[a].push_back(b);
            if (c == 2) adjList[b].push_back(a);
        }
        SCC();
        if (comps.size() == 1) printf("1\n");
        else printf("0\n");
    }
}
