#include <bits/stdc++.h>
using namespace std;

struct edge {
	int from, to, w;
	edge(int from, int to, int w): from(from), to(to), w(w) {}
};

bool vis[1002];
vector<edge> edgeList;
void DFS(int node) {
    vis[node] = 1;
    for (auto e : edgeList) {
        if (e.from != node) continue;
        if (!vis[e.to]) DFS(e.to);
    }
}

vector<int> BellmanFord(int n, int src) {
    vector<int> dist(n+1, 0);
    for (int maxEdges = 0, f = 0; maxEdges < n+1; maxEdges++, f = 0) {
	 	for (auto ne : edgeList) {
			if(dist[ne.to] > dist[ne.from] + ne.w) {
				dist[ne.to] = dist[ne.from] + ne.w;
				f = 1;
		 	}
		}
	 	if (!f)	break;
    } 

	// Extra loop to find the nodes that reside in a negative cycle
	// Perform DFS on these nodes to find all the nodes affected by negative cycles
	memset(vis, 0, sizeof vis);
	for (auto ne : edgeList) {
        if(!vis[ne.from] && dist[ne.to] > dist[ne.from] + ne.w) {
            DFS(ne.from); DFS(ne.to);
        }
    }

    vector<int> ret;
    for (int i = 0; i < n; i++) if (vis[i]) ret.push_back(i);
    return ret;
}

int main() {
    int t, v, e, x, y, w;
    scanf("%d", &t);
    for (int testCase = 1; testCase <= t; testCase++) {
        scanf("%d %d", &v, &e);

        edgeList.clear();
        while (e--) {
            scanf("%d %d %d", &x, &y, &w);
            edgeList.push_back(edge(y, x, w)); // flip the direction of the edges
        }

        vector<int> ans = BellmanFord(v, 0);
        if (ans.empty()) printf("Case %d: impossible\n", testCase);
        else {
            printf("Case %d:", testCase);
            for (auto s : ans) printf(" %d", s);
            printf("\n");
        }
    }
}
