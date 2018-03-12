#include<bits/stdc++.h>
using namespace std;

class AutoMarket {
	public:
    	
    struct automobile {
        int cost, feat, fix;
        automobile(int cost, int feat, int fix):cost(cost),feat(feat),fix(fix) {}
        bool operator <(const automobile &am) const {return cost < am.cost;}
    };
    
    vector<automobile> vc;
    int mem[55][55];
    
    int LIS(int idx, int prv) {
        if (idx == vc.size()) return 0;
        if (prv != -1 && mem[idx][prv] != -1) return mem[idx][prv];
        int Leave = LIS(idx+1, prv);
        int Pick = 0;
        if (prv == -1 || (vc[idx].cost > vc[prv].cost && vc[idx].fix > vc[prv].fix && vc[idx].feat < vc[prv].feat)) Pick = LIS(idx+1, idx) + 1;
        return mem[idx][prv] = max(Leave, Pick);
    }
    
    int maxSet(vector<int> cost, vector<int> features, vector<int> fixTimes) {
        for (int i = 0; i < cost.size(); i++)
            vc.push_back(automobile(cost[i],features[i],fixTimes[i]));
        sort(vc.begin(),vc.end());
        memset(mem,-1,sizeof mem);
        return LIS(0,-1);
    }
};
