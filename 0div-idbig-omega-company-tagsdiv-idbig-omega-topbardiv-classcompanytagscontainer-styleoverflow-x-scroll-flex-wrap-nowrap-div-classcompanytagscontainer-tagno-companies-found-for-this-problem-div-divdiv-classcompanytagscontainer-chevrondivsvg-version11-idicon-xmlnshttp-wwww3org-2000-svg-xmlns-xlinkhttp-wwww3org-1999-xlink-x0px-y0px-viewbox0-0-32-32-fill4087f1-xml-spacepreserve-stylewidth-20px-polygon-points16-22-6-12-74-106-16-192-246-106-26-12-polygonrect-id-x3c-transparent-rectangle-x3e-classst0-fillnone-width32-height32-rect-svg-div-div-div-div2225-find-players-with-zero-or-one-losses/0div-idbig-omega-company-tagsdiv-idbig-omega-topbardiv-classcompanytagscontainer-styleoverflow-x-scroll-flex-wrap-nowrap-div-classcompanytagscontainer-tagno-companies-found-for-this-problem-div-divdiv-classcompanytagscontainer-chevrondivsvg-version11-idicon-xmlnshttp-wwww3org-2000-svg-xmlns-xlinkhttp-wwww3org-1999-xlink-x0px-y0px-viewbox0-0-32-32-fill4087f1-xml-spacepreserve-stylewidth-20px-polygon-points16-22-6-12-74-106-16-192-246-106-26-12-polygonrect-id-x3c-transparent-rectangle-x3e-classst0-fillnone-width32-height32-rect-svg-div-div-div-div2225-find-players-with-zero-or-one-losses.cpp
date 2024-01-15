class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int>mp;
        for(auto m:matches){
            if(mp.find(m[0])== mp.end()) mp[m[0]] = 0;
            mp[m[1]]++;
        }
        vector<vector<int>> ans(2);
        for(auto x:mp){
            if(x.second == 0) ans[0].push_back(x.first);
            else if(x.second == 1) ans[1].push_back(x.first);
        }
        return ans;
    }
};