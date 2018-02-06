#include<bits/stdc++.h>
using namespace std;

int n, t, res, arr[22];
vector<int> tmp, tracks;
void rec(int cd, int mins) {
    if (cd == t) {
        if (mins > res) {res = mins; tracks = tmp;}
        return;
    }

    // Pick
    if (arr[cd] + mins <= n) {
        tmp.push_back(arr[cd]);
        rec(cd+1, mins+arr[cd]);
        tmp.pop_back();
    }

    // Leave
    rec(cd+1, mins);
}

int main() {
    while (scanf("%d %d", &n, &t) != EOF) {
        res = 0;
        for (int i = 0; i < t; i++) scanf("%d", &arr[i]);
        rec(0,0);
        for (auto e : tracks) printf("%d ", e);
        printf("sum:%d\n", res);
        tracks.clear();
    }
}
