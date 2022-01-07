class Solution {
public:
    
    vector<int> nums;
    Solution(vector<int>& nums) {
        this->nums = nums;
    }
    int pick(int target) {
        vector<int> dupIndex;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == target)
                dupIndex.push_back(i);
        }
        int ans = 0;
        for(int i = 0; i<dupIndex.size(); i++){
            if(rand() % (i+1) == 0) ans = dupIndex[i];
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */