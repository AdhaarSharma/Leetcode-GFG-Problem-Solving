class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        int n = nums.size();
        if(!n) return 0;
        sort(nums.begin(), nums.end());
        int preEnd = -1, ans = 0, curStart = -1, curEnd = -1;
        for(int i=0; i<n; i++){
            curStart = max(nums[i][0], preEnd + 1);
            curEnd = max(nums[i][1], preEnd + 1);
            if(nums[i][1] > preEnd) {
                ans += curEnd - curStart + 1;
                preEnd = curEnd;
            }
        }
        return ans;
    }
};