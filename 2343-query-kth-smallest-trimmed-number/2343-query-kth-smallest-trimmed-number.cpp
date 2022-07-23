class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int string_len = nums[0].size();
        vector<int> ans;
        int len = nums.size();
        int n = queries.size();
        for(int i=0; i<n; i++){
            int k = queries[i][0];
            int trimlen = queries[i][1];
            vector<pair<string,int>> vec;
            for(int i=0; i<len; i++)
                vec.push_back({nums[i].substr(string_len-trimlen),i});
            sort(vec.begin(), vec.end());
            ans.push_back(vec[k-1].second);
        }
        return ans;
    }
};