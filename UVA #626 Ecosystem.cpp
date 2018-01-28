#include<bits/stdc++.h>
using namespace std;

bool srtd(vector<int> vc) {
    if (vc[0] < vc[1] && vc[1] < vc[2]) return true;
    if (vc[0] > vc[1] && vc[1] > vc[2]) return true;
    return false;
}

vector<int> tmp;
set<vector<int>> ans;
vector<vector<int>> adjList;
void DFS(int node) {
    tmp.push_back(node);
    for (int i = 0; i < adjList[node].size(); i++) {
        int ch = adjList[node][i];
        if (tmp.size() == 3) {
            if (tmp[tmp.size()-3] == ch) {
                vector<int> t = tmp;
                while (!srtd(t)) rotate(t.begin(), t.begin()+1, t.end());
                ans.insert(t);
            }
        } else if (find(tmp.begin(), tmp.end(), ch) == tmp.end()) DFS(ch);
    }
    tmp.pop_back();
}

int main() {
    int n, x;
    while (scanf("%d", &n) != EOF) {
        adjList.clear(); adjList.resize(n+1);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                scanf("%d", &x);
                if (x) adjList[i].push_back(j);
            }
        }

        ans.clear();
        for (int i = 1; i <= n; i++) DFS(i);

        for (auto e : ans) {
            for (int i = 0; i < e.size(); i++) {
                if (i) printf(" ");
                printf("%d", e[i]);
            }
            printf("\n");
        }
        printf("total:%d\n\n", ans.size());
    }
}
