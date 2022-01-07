class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jump = 0, end = 0, farthest = 0;
        for(int i = 0; i < n-1; i++){
            farthest = max(farthest, i+nums[i]);
            if(i == end){
                end = farthest;
                jump++;
            }
        }
        return jump;
    }
};


class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n, INT_MAX);
        dp[n-1] = 0;
        for(int i=n-2; i>=0; i--){
            int minm = INT_MAX;
            for(int j=i+1; j<=min(n-1,i+nums[i]); j++){
                minm = min(minm,dp[j]);
            }
            if(minm!=INT_MAX)
                dp[i] = minm+1;
        }
        return dp[0];
    }
};