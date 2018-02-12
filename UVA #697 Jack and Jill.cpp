#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-6;
const double PI = acos(-1.0);

double up, diam, lvl, buc, spdU, dwn, vol;
double calc() {
    int cnt = ceil(vol/buc - EPS); // in case the division causes a positive garbage value
    double ret = 0.0;
    while (cnt--) {
        // feet need to be converted into inches
        ret += up + dwn + sqrt(lvl/193.2) + lvl/spdU;
        lvl += (1728*buc) / (PI*diam*diam/4);
    }
    return ret;
}

int main() {
    int t = 1;
    while (scanf("%lf", &up) && up >= 1.0) {
        if (t != 1) printf("\n");
        scanf("%lf %lf %lf %lf %lf %lf", &diam, &lvl, &buc, &spdU, &dwn, &vol);
        printf("Scenario %d:\n", t);
        printf("     up hill%19.2lf sec\n", up);
        printf("     well diameter%13.2lf in\n", diam);
        printf("     water level%15.2lf in\n", lvl);
        printf("     bucket volume%13.2lf cu ft\n", buc);
        printf("     bucket ascent rate%8.2lf in/sec\n", spdU);
        printf("     down hill%17.2lf sec\n", dwn);
        printf("     required volume%11.2lf cu ft\n", vol);
        printf("     TIME REQUIRED%13.2lf sec\n", calc());
        t++;
    }
}
