#include <bits/stdc++.h>
using namespace std;
const int INF = (1 << 31) - 1;

struct edge {
    int from, to, w;
    edge(int from, int to, int w): from(from), to(to), w(w) {}
};

bool BellmanPrcoessing(vector<edge> & edgeList, int n, vector<int> &dist, vector<int> &dist2) {
	for (int maxEdges = 0, f = 0; maxEdges < n+1; maxEdges++, f = 0) {
		
    // This loop is for the sole purpose of making the reachCycle calculations work
    for (int j = 0; j < edgeList.size() ; ++j) {
			edge ne = edgeList[j];
			if (dist2[ne.from] >= INF || ne.w >= INF) continue;

			if (dist2[ne.from] + ne.w < dist2[ne.to]) {
				dist2[ne.to] = dist2[ne.from] + ne.w;
				f = 1;
			}
		}
    
    // This loop is for calculating the actual distance while making sure we don't run out of energy
		for (int j = 0; j < edgeList.size() ; ++j) {
			edge ne = edgeList[j];
			if (dist[ne.from] >= INF || ne.w >= INF)	continue;

			if (dist[ne.from] + ne.w < min(100, dist[ne.to])) {
				dist[ne.to] = dist[ne.from] + ne.w;
				f = 1;
				if(maxEdges == n) return true;
			}
		}
		if (!f)	break;
	}
	return false;
}

bool BellmanFord(vector<edge> &edgeList, int n, int src, int dest) {	// O(NE)
	vector<int> dist(n, INF), dist2(n, INF), reachCycle(n, 0);
	dist[src] = dist2[src] = 0;

	bool cycle = BellmanPrcoessing(edgeList, n, dist, dist2);

	if(cycle) {
		vector<int> odist = dist2;
		BellmanPrcoessing(edgeList, n, dist, dist2);
		for (int i = 0; i < n; ++i)	// find all nodes that AFFECTED by negative cycle
			reachCycle[i] = (odist[i] != dist2[i]);
	}

	return (dist[dest] < 100 || reachCycle[dest]);
}

int main() {
    int n, e, k, x;
    while (scanf("%d", &n) && n != -1) {
        vector<edge> edgeList;
        vector<int> energy(n);
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &e, &k);
            energy[i] = -e;
            while (k--) {
                scanf("%d", &x);
                edgeList.push_back(edge(i, x-1, -1));
            }
        }

        for (int i = 0; i < edgeList.size(); i++)
            edgeList[i].w = energy[edgeList[i].to];

        if (BellmanFord(edgeList, n, 0, n-1)) printf("winnable\n");
        else printf("hopeless\n");
    }
}
