class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        vector<vector<int>> ans;
        vector<vector<int>> sizeMap(n+1,vector<int>());
        for(int i=0; i<n; i++){
            sizeMap[groupSizes[i]].push_back(i);
            if(sizeMap[groupSizes[i]].size()>=groupSizes[i]){
                ans.push_back(sizeMap[groupSizes[i]]);
                sizeMap[groupSizes[i]].clear();
            }
        }
        for(auto s:sizeMap){
            if(!s.empty()) ans.push_back(s);
        }
        return ans;
    }
};