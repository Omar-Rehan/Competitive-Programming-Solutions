#include<bits/stdc++.h>
using namespace std;

int n, arr[2002];
vector<int> tmp;

int LIS(int strt, int idx) {
    int ret;
    tmp.clear();
    for (int i = idx; i < n; i++) { // Longest Increasing Subsequence starting from "strt"
        if (arr[i] < strt) continue;
        int pos = lower_bound(tmp.begin(), tmp.end(), arr[i]) - tmp.begin();

        if (pos == tmp.size()) tmp.push_back(arr[i]);
        else tmp[pos] = arr[i];
    }
    ret = tmp.size();
    tmp.clear();

    for (int i = idx; i < n; i++) { // Longest Decreasing Subsequence starting from "strt"
        if (-arr[i] < -strt) continue;
        int pos = lower_bound(tmp.begin(), tmp.end(), -arr[i]) - tmp.begin();

        if (pos == tmp.size()) tmp.push_back(-arr[i]);
        else tmp[pos] = -arr[i];
    }
    return ret + tmp.size() - 1;
}

int main() {
    int t, res;
    scanf("%d", &t);
    while (t--) {
        res = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
        for (int i = 0; i < n; i++) res = max(res, LIS(arr[i], i));
        printf("%d\n", res);
    }
}
