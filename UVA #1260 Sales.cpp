#include<bits/stdc++.h>
using namespace std;

int main() {
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        int arr[n], res = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
            for (int j = 0; j < i; j++) res += (arr[j] <= arr[i]);
        }
        printf("%d\n", res);
    }
}
