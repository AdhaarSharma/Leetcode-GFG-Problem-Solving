class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int len = nums.size();
        vector<int> res;
        for(int i=0; i<len; i++) {
            int m = abs(nums[i])-1; // index start from 0
            if(nums[m]<0) res.push_back(m+1);
            nums[m] = -nums[m];
        }
        return res;
    }
};