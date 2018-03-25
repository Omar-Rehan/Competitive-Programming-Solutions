#include<bits/stdc++.h>
using namespace std;

set<int> supers;
vector<int> lis, lengths;
vector<vector<int>> indexes;
int n, t = 10, arr[100002], vis[100002];

void LIS() {
    lis.clear();
    supers.clear();
    lengths.clear();
    indexes.clear(); indexes.resize(n+1);
    for (int i = 0; i < n; i++) {
        int pos = lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();

        if (pos == lis.size()) lis.push_back(arr[i]);
        else lis[pos] = arr[i];

        lengths.push_back(pos+1);
        indexes[pos+1].push_back(i);
    }
}

void Trace(int idx) {
    if (vis[idx] == t) return;
    vis[idx] = t;
    
    if (lengths[idx] == 1) {
        supers.insert(arr[idx]);
        return;
    }
    
    supers.insert(arr[idx]);
    
    int pos = lower_bound(indexes[lengths[idx]-1].begin(), indexes[lengths[idx]-1].end(), idx) - indexes[lengths[idx]-1].begin();
    for (; pos > 0 && arr[indexes[lengths[idx]-1][pos-1]] < arr[idx]; pos--)
        Trace(indexes[lengths[idx]-1][pos-1]);
}

int main() {
    memset(vis, -1, sizeof vis);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
        
        LIS();
        for (int i = 0; i < indexes[lis.size()].size(); i++)
            Trace(indexes[lis.size()][i]);
            
        printf("%d\n", supers.size());
        for (auto e : supers) printf("%d ", e);
        printf("\n");
    }
}
