#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m, x, y;
    while (scanf("%d %d", &n, &m) != EOF) {
        int arr[n+2] = {0};
        map<int,vector<int>> mp;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &arr[i]);
            mp[arr[i]].push_back(i);
        }
        while (m--) {
            scanf("%d %d", &x, &y);
            printf("%d\n", (!mp[y].empty() && x <= mp[y].size() ? mp[y][x-1] : 0));
        }
    }
}
