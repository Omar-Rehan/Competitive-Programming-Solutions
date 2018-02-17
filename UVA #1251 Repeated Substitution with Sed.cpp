#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;
#define f first
#define s second

string b;
int n, res;
map<string,int> vis;
vector<pair<string,string>> vc;

void rec(int num, string str) {
    if (str == b) res = min(res, num);
    if (num >= res || str.length() > b.length() || (vis.find(str) != vis.end() && vis[str] <= num)) return;
    vis[str] = num;

    for (int i = 0; i < vc.size(); i++) {
        int w = 0;
        string tmp = str;
        while ((w = (int)tmp.find(vc[i].f, w)) != -1) {
            tmp.replace(w, vc[i].f.length(), vc[i].s);
            w += vc[i].s.length();
        }
        if (tmp != str) rec(num+1, tmp);
    }
}

int main() {
    string a, x, y;
    while (scanf("%d", &n) && n) {
        for (int i = 0; i < n; i++) {
            cin >> x >> y;
            if (x != y) vc.push_back(make_pair(x,y));
        }
        cin >> a >> b;
        res = INF;
        rec(0, a);
        if (res == INF) printf("-1\n");
        else printf("%d\n", res);
        vc.clear();
        vis.clear();
    }
}
