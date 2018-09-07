#include <bits/stdc++.h>
using namespace std;

vector<int> nums;
int testCase = 0, vis[10000];
int BFS(int strt, int fnsh) {
    queue<int> q;
    q.push(strt);

    int crnt, dpth = 0, sz = 1;
    for (; !q.empty() && dpth < 10000; dpth++, sz = q.size()) {
        while (sz--) {
            crnt = q.front(); q.pop();
            for (auto n : nums) {
                int tmp = (crnt + n) % 10000;
                if (tmp == fnsh) return dpth + 1;
                if (vis[tmp] != testCase) {
                    q.push(tmp);
                    vis[tmp] = testCase;
                }
            }
        }
    }
    return -1;
}

int main() {
    int strt, fnsh, buttons, x;
    while (scanf("%d %d %d", &strt, &fnsh, &buttons) && (strt || fnsh || buttons)) {
        testCase++;
        for (int i = 0; i < buttons; i++)
            scanf("%d", &x), nums.push_back(x);

        int ans = BFS(strt, fnsh);
        if (ans != -1) printf("Case %d: %d\n", testCase, ans);
        else printf("Case %d: Permanently Locked\n", testCase);

        nums.clear();
    }
}
