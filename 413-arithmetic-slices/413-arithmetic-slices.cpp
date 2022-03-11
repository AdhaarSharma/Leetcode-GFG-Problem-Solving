class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int total=0, curr=0;
        for(int i=2; i<nums.size(); i++){
            if(nums[i]-nums[i-1]==nums[i-1]-nums[i-2]){
                curr++;
                total+=curr;
            } else {
                curr=0;
            }
        }
        return total;
    }
};