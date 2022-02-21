class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int res=0, left=-1, right=-1;
        sort(intervals.begin(),intervals.end());
        for(auto &v:intervals){
            if(left<v[0] && right<v[1]){
                left=v[0];
                res++;
            }
            right=max(right,v[1]);
        }
        return res;
    }
};