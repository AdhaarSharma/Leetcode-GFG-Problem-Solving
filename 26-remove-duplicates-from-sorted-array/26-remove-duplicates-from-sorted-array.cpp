class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int l=0,r=1;
        int val=nums[0];
        while(r<n){
            while(r<n and val==nums[r]){
                r++;
            }
            if(r>=n){
                break;
            }
            val=nums[r];
            swap(nums[l+1],nums[r]);
            l++;
            r++;
        }
        return l+1;
    }
};