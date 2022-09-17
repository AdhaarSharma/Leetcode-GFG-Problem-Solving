class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int>start;
        vector<int>end;
        for(auto a:intervals){
            start.push_back(a[0]);
            end.push_back(a[1]);
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        int ans = 1, result = 1;
        int i=0, j=1;
        while(i<n && j<n){
            if(j<n && end[i]>=start[j]){
                ans++;
                j++;
            }
            else{
                ans--;
                i++;
            }
            result = max(ans, result);
        }
        return result;
        
    }
};