class Solution {
public:
    
    vector<int> nums;
    Solution(vector<int>& nums) {
        this->nums = nums;
    }
    int pick(int target) {
        int n = 0, ans = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] != target) continue;
            n++;
            if(rand() % n == 0) ans = i;
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */