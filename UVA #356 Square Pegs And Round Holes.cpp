#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    bool firstCase = true;
    while (scanf("%d", &n) != EOF) {
        if (!firstCase) printf("\n");
        firstCase = false;
        int res1 = 0, res2 = 0;
        double r1, r2, r = 1.0 * n - 0.5;
        // Check all squares in one quarter
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                r1 = sqrt(i*i + j*j); // The distance from the origin to the closer corner of the square
                r2 = sqrt((i+1)*(i+1) + (j+1)*(j+1)); // The distance to the farther corner of the square
                if (r >= r1 && r <= r2) res1++; // If the circumference passes through the square
                if (r >  r1 && r >  r2) res2++; // If the circumference contains the square without passing through it
            }
        }
        printf("In the case n = %d, %d cells contain segments of the circle.\n", n, 4*res1);
        printf("There are %d cells completely contained in the circle.\n", 4*res2);
    }
}
