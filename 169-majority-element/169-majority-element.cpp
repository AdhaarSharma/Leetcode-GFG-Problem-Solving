class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0, res=0;
        for(auto&a:nums){
            if(count==0)
                res = a;
            if(a == res)
                count++;
            else
                count--;
        }
        return res;
    }
};