#include<bits/stdc++.h>
using namespace std;

int main() {
    int s, p, y, j;
    while (scanf("%d %d %d %d", &s, &p, &y, &j) != EOF) {
        int turtle = (j + 12 - y - p) / 3;
        int cat = (j + 12 - s - turtle) / 2;
        int dog = (j + 12 - cat - turtle);
        printf("%d %d %d\n", dog, cat, turtle);
    }
}
