class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        long long unique = 0, ans = 0, sum = 0;
        unordered_map<int, int> ump;
        for(int f = 0, b = 0; f < nums.size(); ++f){
            sum += nums[f];
            ump[nums[f]]++;
            if(ump[nums[f]] == 1) unique++;
            if(f >= k){
                sum -= nums[b];
                ump[nums[b]]--;
                if(ump[nums[b]] == 0) unique--;
                b++;
            }
            if(unique >= m) ans = max(ans, sum);
        }
        return ans;
    }
};