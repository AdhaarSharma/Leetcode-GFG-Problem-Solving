//Map
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int size = nums.size();
        int target = -x;
        for(auto i:nums) target += i;
        if(target == 0) return size;
        map<int,int> mp;
        mp.insert({0,-1});
        int res = -1, sum = 0;
        for(int i=0; i<size; i++){
            sum += nums[i];
            if(mp.find(sum - target) != mp.end())
                res = max(res,i-mp[sum - target]);
            mp.insert({sum,i});
        }
        return res == -1 ? -1 : size-res;
    }
};

//Sliding Window
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int size = nums.size();
        int target = -x;
        for(auto i:nums) target += i;
        if(target == 0) return size;
        if(target < 0) return -1;
        int res = -1, sum = 0, left = 0;
        for(int i=0; i<size; i++){
            sum += nums[i];
            while(sum > target)
                sum -= nums[left++];
            if(sum == target)
                res = max(res, i-left+1);
        }
        return res == -1 ? -1 : size-res;
    }
    
//DP
//C++ Memoization-->TLE
class Solution {
    unordered_map<string,int> mem;
    int solve(vector<int>& nums,int x,int left,int right,int count)
    {
        if(x==0)    //Sum found
            return count;
        if(x<0 or left>right)   //Out of bounds
            return 1e6;
        string key = to_string(left)+"*"+to_string(right)+"*"+to_string(x); //Form Key
        if(mem.count(key))  //Check if already calculated
            return mem[key];
        
        int l = solve(nums,x-nums[left],left+1,right,count+1);  //Include left element
        int r = solve(nums,x-nums[right],left,right-1,count+1); //Include right element
        return mem[key] = min(l,r);
    }
public:
    int minOperations(vector<int>& nums, int x) {
        int ans = solve(nums,x,0,nums.size()-1,0);
        return ans>=1e6?-1:ans;
    }
};