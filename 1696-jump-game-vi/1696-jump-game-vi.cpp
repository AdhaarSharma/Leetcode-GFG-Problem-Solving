class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        vector<int> dp(nums.size(), INT_MIN);
        multiset<int> ms{dp[0] = nums[0]};
        for(int i=1; i<nums.size(); i++){
            if(i>k) ms.erase(ms.find(dp[i-k-1]));
            ms.insert(dp[i] = nums[i] + *rbegin(ms));
        }
        return dp.back();
    }
};