#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> tmp, nums;
deque<int> len1, len2; 
// len1 -> each element at the end of a longest increasing subsequence
// len2 -> each element at the beginning of a longest decreasing subsequence

void LIS(bool b) { // O(n.log(n))
    tmp.clear();
    for (int i = 0; i < n; i++) {
        int pos = lower_bound(tmp.begin(),tmp.end(),nums[i]) - tmp.begin();

        if (pos == tmp.size()) tmp.push_back(nums[i]);
        else tmp[pos] = nums[i];

        if (b) len1.push_back(pos + 1);
        else len2.push_front(pos + 1);
    }
}

int main() {
    int x, ans;
    while (scanf("%d", &n) != EOF) {
        len1.clear();
        len2.clear();
        nums.clear();
        for (int i = 0; i < n; i++) {
            scanf("%d", &x);
            nums.push_back(x);
        }
        ans = 0;
        LIS(1);
        reverse(nums.begin(),nums.end());
        LIS(0);
        for (int mid = 0; mid < n; mid++) 
            ans = max(ans, 2 * min(len1[mid], len2[mid]) - 1);
        printf("%d\n", ans);
    }
}
