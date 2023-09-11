class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        vector<vector<int>> ans;
        vector<vector<int>> sizeMap(n+1,vector<int>());
        for(int i=0; i<n; i++){
            vector<int> *group = &sizeMap[groupSizes[i]];
            (*group).push_back(i);
            if((*group).size()>=groupSizes[i]){
                ans.push_back(*group);
                (*group).clear();
            }
        }
        for(auto s:sizeMap){
            if(!s.empty()) ans.push_back(s);
        }
        return ans;
    }
};