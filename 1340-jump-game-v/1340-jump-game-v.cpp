class Solution {
public:
    int dp[1001] = {};
    int maxJumps(vector<int>& arr, int d, int res=1) {
        for(auto i = 0; i < arr.size(); i++)
            res = max(res, dfs(arr, d, i));
        return res;
    }
    int dfs(vector<int>& arr, int d, int i, int res = 1){
        if(dp[i]) return dp[i];
        for(auto j = i-1; j>=max(0, i-d) && arr[i]>arr[j]; j--)
            res = max(res, 1+dfs(arr, d, j));
        for(auto j = i+1; j<=min((int)arr.size()-1, i+d) && arr[i]>arr[j]; j++)
            res = max(res, 1+dfs(arr, d, j));
        return dp[i] = res;
    }
};