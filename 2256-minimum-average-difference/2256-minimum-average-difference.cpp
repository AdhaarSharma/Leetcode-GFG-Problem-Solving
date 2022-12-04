class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long long int sum = 0; int n = nums.size();
        vector<int>left(n,0), right(n,0);
        for(int i=0; i<n; i++){
            sum += nums[i];
            left[i] = sum/(i+1);
        }
        sum = 0;
        for(int i=n-1; i>=0; i--){
            sum += nums[i];
            right[i] = sum/(n - i);
        }
        int ans = left[n-1];
        int idx = n - 1;
        for(int i = n - 2; i >= 0; i--){
            int curr_average = abs(left[i] - right[i+1]);
            if(curr_average <= ans){
                ans = curr_average;
                idx = i;
            }
        }
        return idx;
    }
};