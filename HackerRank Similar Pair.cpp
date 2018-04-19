#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll cnt = 0;
const int MAX = (1e5) + 2;
bool NotARoot[MAX] = {false};
vector<vector<int>> adjList(MAX);
int n, k, tree[4*MAX] = {0};

int Query(int p, int l, int r, int s, int e) {
    if (e < l || s > r) return 0;
    if (s <= l && e >= r) return tree[p];
    int mid = (l + r) / 2;
    int q1 = Query(2*p, l, mid, s, e);
    int q2 = Query(2*p+1, mid+1, r, s, e);
    return q1 + q2;
}

void Update(int p, int l, int r, int idx, bool val) {
    if (idx < l || idx > r) return;
    if (idx == l && idx == r) {
        tree[p] = val;
        return;
    }
    int mid = (l + r) / 2;
    Update(2*p, l, mid, idx, val);
    Update(2*p+1, mid+1, r, idx, val);
    tree[p] = tree[2*p] + tree[2*p+1];
}

void DFS(int node) {
    cnt += Query(1, 1, n, max(1, node-k), min(n, node+k));
    Update(1, 1, n, node, 1);
    for (int i = 0; i < adjList[node].size(); i++) {
        int ch = adjList[node][i];
        DFS(ch);
    }
    Update(1, 1, n, node, 0);
}

int main() {
    int p, c, root;
    scanf("%d %d", &n, &k);
    for (int i = 1; i < n; i++) {
        scanf("%d %d", &p, &c);
        adjList[p].push_back(c);
        NotARoot[c] = true;
    }
    for (int i = 1; i < n; i++)
        if (!NotARoot[i]) {root = i; break;}
    DFS(root);
    printf("%lld", cnt);
}
