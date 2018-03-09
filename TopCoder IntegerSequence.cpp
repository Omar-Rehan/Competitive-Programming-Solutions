#include<bits/stdc++.h>
using namespace std;

class IntegerSequence {
    public:
    
    	vector<int> nums, tmp;
    	deque<int> len1, len2;
      
    	void LIS(bool b) {
          tmp.clear();
          for (int i = 0; i < nums.size(); i++) {
        		int pos = lower_bound(tmp.begin(),tmp.end(),nums[i]) - tmp.begin();

        		if (pos == tmp.size()) tmp.push_back(nums[i]);
        		else tmp[pos] = nums[i];

        		if (b) len1.push_back(pos + 1);
        		else len2.push_front(pos + 1);
    		  }
    	}
      
    	int maxSubsequence(vector<int> numbers) {
            nums = numbers;
        	LIS(1);
        	reverse(nums.begin(),nums.end());
        	LIS(0);
            int ans = 0;
        	for (int mid = 0; mid < nums.size(); mid++) ans = max(ans, len1[mid] + len2[mid] - 1);
            return (nums.size()-ans);
        }
};
