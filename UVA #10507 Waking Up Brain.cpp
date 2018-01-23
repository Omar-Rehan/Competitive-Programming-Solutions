#include<bits/stdc++.h>
using namespace std;

string strt;
bool awake[30];
vector<vector<int>> adjList;
int BFS() {
    queue<int> q;
    int crnt, sz = 3, dpth = 0;
    q.push(strt[0]-'A'); q.push(strt[1]-'A'); q.push(strt[2]-'A');
    for (; !q.empty(); sz = q.size(), dpth++) {
        vector<int> tmp;
        while (sz--) {
            crnt = q.front();
            q.pop();
            if (awake[crnt]) continue;
            int cnt = 0;
            for (int i = 0; i < adjList[crnt].size(); i++) {
                int child = adjList[crnt][i];
                cnt += (awake[child]);
            }
            if (cnt < 3 && dpth) continue;
            tmp.push_back(crnt);
            for (int i = 0; i < adjList[crnt].size(); i++) {
                int child = adjList[crnt][i];
                if (!awake[child]) q.push(child);
            }
        }
        for (auto e : tmp) awake[e] = 1;
    }
    return dpth-1;
}

int main() {
    int n, cnc;
    char cc1[5], cc2[5];
    string tmp;
    while (scanf("%d %d %s", &n, &cnc, &cc1) != EOF) {
        strt = cc1;
        memset(awake, 0, sizeof awake);
        adjList.clear(); adjList.resize(30);
        while (cnc--) {
            scanf("%s", &cc2);
            tmp = cc2;
            adjList[tmp[0]-'A'].push_back(tmp[1]-'A');
            adjList[tmp[1]-'A'].push_back(tmp[0]-'A');
        }
        int cnt = 0, dpth = BFS();
        for (int i = 0; i < 30; i++) cnt += (awake[i]);
        if (cnt == n) printf("WAKE UP IN, %d, YEARS\n", dpth);
        else printf("THIS BRAIN NEVER WAKES UP\n");
    }
}
