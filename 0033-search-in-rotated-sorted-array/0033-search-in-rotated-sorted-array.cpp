class Solution {
public:
    int searchBS(vector<int>& nums, int target, int i, int j){
        int l = i, h = j;
        while(l<=h){
            int mid = l + (h-l)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] > target){
                h = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size(), l = 0, h = n-1;
        while(l <= h){
            int mid = l + (h-l)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] > nums[h]){
                if(nums[l] <= target && target < nums[mid])
                    return searchBS(nums, target, l, mid - 1);
                else
                    l = mid + 1;
            }
            else {
                if(nums[mid] < target && target <= nums[h])
                    return searchBS(nums, target, mid + 1, h);
                else
                    h = mid - 1;
            }
        }
        return -1;
    }
};