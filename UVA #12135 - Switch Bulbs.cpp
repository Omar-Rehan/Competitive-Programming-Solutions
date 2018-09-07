#include <bits/stdc++.h>
using namespace std;
const int INF = (1 << 31) - 1;

int flipBit(int msk, int idx) {return (msk ^ (1 << idx));}

vector<vector<int>> switches;
vector<int> BFS() {
    vector<int> len(1 << 16, INF);
    queue<int> q;
    q.push(0); 
    len[0] = 0;

    int dpth = 0, crnt = 0, sz = 1;
    for (; !q.empty(); dpth++, sz = q.size()) {
        while (sz--) {
            crnt = q.front(); q.pop();
            for (auto e : switches) {
                int tmp = crnt;
                for (auto f : e) tmp = flipBit(tmp, f);
                if (len[tmp] == INF) {
                    q.push(tmp);
                    len[tmp] = dpth+1;
                }
            }
        }
    }
    return len;
}

int main() {
    int t, n, m, k, x, q;
    scanf("%d", &t);
    for (int w = 1; w <= t; w++) {
        printf("Case %d:\n", w);
        scanf("%d %d", &n, &m);
        switches.clear(); switches.resize(m);
        for (int i = 0; i < m; i++) {
            scanf("%d", &k);
            while (k--)
                scanf("%d", &x), switches[i].push_back(x);
        }
        
        vector<int> len = BFS();
        scanf("%d", &q);
        char desired[n+2];
        while (q--) {
            scanf("%s", &desired);
            int mask = 0;
            for (int i = 0; i < n; i++) {
                if (i) mask <<= 1;
                if (desired[i] == '1') mask++;
            }
            
            printf("%d\n", (len[mask] == INF ? -1 : len[mask]));
        }
        printf("\n");
    }
}
