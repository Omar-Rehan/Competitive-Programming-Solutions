#include <bits/stdc++.h>
using namespace std;

int n, c = 1, builds[10005][2], mem[10005][10005], vis[10005][10005] = {0};
bool mode;

int LIS(int idx, int prv){
    if (idx == n+1) return 0;
    if (vis[idx][prv] == c) return mem[idx][prv];
    int choice1 = LIS(idx+1, prv); // Leave
    int choice2 = 0;
    if (mode){
        if (builds[prv][0] < builds[idx][0]) choice2 = LIS(idx+1, idx) + builds[idx][1]; // Pick
    } else {
        if (builds[prv][0] > builds[idx][0]) choice2 = LIS(idx+1, idx) + builds[idx][1]; // Pick
    }
    vis[idx][prv] = c;
    return mem[idx][prv] = max(choice1, choice2);
}

int main(){
    int t;
    cin >> t;
    while (c <= 2*t){
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> builds[i][0];
        for (int i = 1; i <= n; i++) cin >> builds[i][1];
        builds[0][0] = -1000000000;
        mode = true;
        int inc = LIS(1,0);
        builds[0][0] = 1000000000;
        mode = false;
        c++;
        int dec = LIS(1,0);
        if (dec > inc){
            cout << "Case " << c/2 << ". Decreasing (" << dec << "). " << "Increasing (" << inc << ")." << endl;
        } else {
            cout << "Case " << c/2 << ". Increasing (" << inc << "). " << "Decreasing (" << dec << ")." << endl;
        }
        c++;
    }
    return 0;
}
