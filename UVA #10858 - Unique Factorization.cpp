#include <bits/stdc++.h>
using namespace std;

vector<int> genDivisors(int n) { // generate all divisors except 1
    vector<int> ret(1, n);
    int i;
    for (i = 2; i*i < n; i++)
        if (n%i == 0) ret.push_back(i), ret.push_back(n/i);
    if (i*i == n) ret.push_back(i);
    return ret;
}

vector<int> vc;
set<vector<int>> ans;

void rec(int n) {
    if (n == 1) { // base case
        vector<int> tmp = vc;
        sort(tmp.begin(), tmp.end());
        if (tmp.size() > 1) ans.insert(tmp);
        return;
    }

    vector<int> divisors = genDivisors(n);
    for (auto e : divisors) { // recursive calls (backtrack)
        vc.push_back(e);
        rec(n / e);
        vc.pop_back();
    }
}

int main() {
    int n;
    while (scanf("%d", &n) && n) {
        rec(n);
        printf("%d\n", ans.size());
        for (auto e : ans) {
            for (int i = 0; i < e.size(); i++)
                printf("%d%c", e[i], i == e.size()-1 ? '\n' : ' ');
        }
        ans.clear();
    }
}
