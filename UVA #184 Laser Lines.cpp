#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-9;

struct point {
    int x, y;
    point() {x = y = 0;}
    point(int _x, int _y): x(_x), y(_y) {}
    bool operator < (point other) const {
        if (abs(x - other.x) > EPS) return x < other.x;
        return y < other.y;
    }
    bool operator == (point other) const {
        return (abs(x - other.x) < EPS && abs(y - other.y) < EPS);
    }
};

struct line {
    double a, b, c;
    bool operator < (line other) const {
        if (fabs(a - other.a) > EPS) return a < other.a;
        if (fabs(b - other.b) > EPS) return b < other.b;
        if (fabs(c - other.c) > EPS) return c < other.c;
        return false;
    }
    bool operator == (line other) const {
        return (fabs(a - other.a) < EPS && fabs(b - other.b) < EPS && fabs(c - other.c) < EPS);
    }
};
line pointsToLine(point p1, point p2) {
    line l;
    if (p1.x == p2.x) {
        l.a = 1.0;
        l.b = 0.0;
        l.c = -p1.x;
    } else {
        l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
        l.b = 1.0;
        l.c = -(double)(l.a * p1.x) - p1.y;
    }
    return l;
}

struct vec {
    double x, y;
    vec(double _x, double _y): x(_x), y(_y) {}
};
vec toVector(point a, point b) {return vec(b.x - a.x, b.y - a.y);}
double crossProd(vec a, vec b) {return a.x * b.y - a.y * b.x;}

bool collinear(point p, point q, point r) {
    return fabs(crossProd(toVector(p, q), toVector(p, r)) < EPS);
}

int main() {
    int x, y;
    while (scanf("%d %d", &x, &y) && (x || y)) {
        // Take in Input
        vector<point> pnts;
        pnts.push_back(point(x,y));
        while (scanf("%d %d", &x, &y) && (x || y)) pnts.push_back(point(x, y));

        // Fill Map
        bool found = false;
        map<line, set<point>> mp;
        for (int i = 0; i < pnts.size()-1; i++) {
            for (int j = i+1; j < pnts.size(); j++) {
                line l = pointsToLine(pnts[i], pnts[j]);
                mp[l].insert(pnts[i]);
                mp[l].insert(pnts[j]);
                if (mp[l].size() > 2) found = true;
            }
        }

        // Print Output
        set<set<point>> st;
        if (found) {
            printf("The following lines were found:\n");
            for (auto e : mp) if (e.second.size() > 2) st.insert(e.second);
            for (auto e : st) {
                for (auto f : e) {
                    printf("(%4d,%4d)", f.x, f.y);
                }
                printf("\n");
            }
        } else {
            printf("No lines were found\n");
        }

    }
}
