#include <bits/stdc++.h>
using namespace std;

int n, m, mem[1000][1000], grid[1000][1000];
int dp(int r, int c) {
    if (r > n || c > m || grid[r][c]) return 0;
    if (r == n && c == m) return 1;
    int &ret = mem[r][c];
    if (ret != -1) return ret;
    int Right = dp(r, c+1);
    int Down = dp(r+1, c);
    return ret = Right + Down;
}

int main() {
    //freopen("output.txt","w", stdout);
    int t;
    string s;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        memset(grid, 0, sizeof grid);
        memset(mem, -1, sizeof mem);
        cin.ignore();
        for (int i = 1; i <= n; i++) {
            getline(cin, s);
            istringstream iss(s);
            int x, c = 0;
            while (iss >> x){
                if (c) grid[i][x] = 1;
                c = 1;
            }
        }
        cout << dp(1,1) << endl;
        if (t) cout << endl;
    }
}
