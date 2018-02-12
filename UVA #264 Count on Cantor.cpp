#include <bits/stdc++.h>
using namespace std;

int arr[10000005][2];

int main() {
    bool a = 0, b = 1;
    int n, topA = 1, topB = 2, tmpA = 1, tmpB = 1;
    for (int i = 1; i <= 1e7; i++) {
        if (tmpA == 1) {
            arr[i][0] = arr[i+1][0] = 1;
            i++;
            topA += 2;
            tmpA++;
            a = 1;
        } else {
            arr[i][0] = tmpA;
            tmpA += (a ? 1 : -1);
            if (tmpA == topA) a = 0;
        }
    }
    for (int i = 1; i <= 1e7; i++) {
        if (tmpB == 1 && i != 1) {
            arr[i][1] = arr[i+1][1] = 1;
            i++;
            topB += 2;
            tmpB++;
            b = 1;
        } else {
            arr[i][1] = tmpB;
            tmpB += (b ? 1 : -1);
            if (tmpB == topB) b = 0;
        }
    }
    while (scanf("%d", &n) != EOF)
        printf("TERM %d IS %d/%d\n", n, arr[n][0], arr[n][1]);
}
