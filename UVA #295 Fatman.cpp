#include <bits/stdc++.h>
using namespace std;

bool prob[105];
int n, distSqr[105][105];
int Sqr(int a) {return a*a;}
bool check(int sz) {
    memset(prob, 0, sizeof prob);
    prob[n] = 1;
    queue<int> q;
    q.push(n); // Initiallty we try to pass UNDER every point (just over the ground)
    while (!q.empty()) {
        int crnt = q.front(); q.pop();
        for (int i = 0; i < n+2; i++) {
            if (!prob[i] && distSqr[i][crnt] < sz) { // Weed out the problematic points
                prob[i] = 1;
                q.push(i);
            }
        }
    }
    return !prob[n+1];
}

int main() {
    int t, l, w;
    scanf("%d", &t);
    for (int q = 1; q <= t; q++) {
        scanf("%d %d %d", &l, &w, &n);
        int arr[n+2][2];
        for (int i = 0; i < n; i++) scanf("%d %d", &arr[i][0], &arr[i][1]);

        // Calculate distances
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                distSqr[i][j] = distSqr[j][i] = Sqr(arr[i][0]-arr[j][0]) + Sqr(arr[i][1]-arr[j][1]);
            }
            distSqr[i][n] = distSqr[n][i] = Sqr(arr[i][1]); // To ground
            distSqr[i][n+1] = distSqr[n+1][i] = Sqr(w-arr[i][1]); // To ceiling
        }
        distSqr[n][n+1] = distSqr[n+1][n] = w*w;

        // Binary Search
        int strt = 0, fnsh = w*w;
        while (fnsh-strt > 1) {
            int mid = (fnsh - strt) / 2 + strt;
            if (check(mid)) strt = mid;
            else fnsh = mid-1;
        }
        printf("Maximum size in test case %d is %0.4f.\n", q, (check(fnsh) ? sqrt(fnsh) : sqrt(strt)));
    }
}
