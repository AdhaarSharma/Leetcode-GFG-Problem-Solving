class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int m = strs.size();
        int n = strs[0].size();
        int ans = 0;
        for(int j=0; j<n; j++) {
            for(int i=1; i<m; i++) {
                if((strs[i][j] < strs[i-1][j])){
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};