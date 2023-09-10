class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        vector<int> v(102, 0);
        for(auto n: nums){ v[n[0]]++; v[n[1]+1]--; }
        int ans = 0, sum = 0;
        for(int i = 1; i <= 100; ++i){
            sum += v[i];
            if(sum) ans++;
        }
        return ans;
    }
};