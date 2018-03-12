#include<bits/stdc++.h>
using namespace std;

struct elephant {
    int w, iq, id;
    elephant(int w, int iq, int id):w(w),iq(iq),id(id) {}
    bool operator <(const elephant &e) const {return w < e.w;}
};

vector<elephant> vc;
int mem[1002][1002];
bool picked[1002][1002] = {0};

int LIS(int idx, int prv) {
    if (idx == vc.size()) return 0;
    if (mem[idx][prv] != -1) return mem[idx][prv];
    int Pick = 0, Leave = LIS(idx+1, prv);
    if (!prv || (vc[idx].w > vc[prv].w && vc[idx].iq < vc[prv].iq))
        Pick = LIS(idx+1, idx) + 1;
    if (Pick > Leave) {
        picked[idx][prv] = true;
        return mem[idx][prv] = Pick;
    }
    picked[idx][prv] = false;
    return mem[idx][prv] = Leave;
}

int main() {
    int w, iq, res, cnt = 1;
    vc.push_back(elephant(0,0,0));
    while (scanf("%d %d", &w, &iq) != EOF && iq != 0)
        vc.push_back(elephant(w,iq,cnt++));
    sort(vc.begin(),vc.end());
    memset(mem,-1,sizeof mem);
    printf("%d\n", res = LIS(1,0));
    int idx = 0, prv = 0;
    for (auto e : vc) {
        if (picked[idx][prv]) {
            printf("%d\n", e.id);
            prv = idx;
        }
        idx++;
    }
}
