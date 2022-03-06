class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(),pairs.end());
        int mlc[n];
        for(int i=0; i<n; i++)
            mlc[i]=1;
        for(int i=1; i<n; i++)
            for(int j=0; j<i; j++)
                if(pairs[i][0]>pairs[j][1] && mlc[i]<mlc[j]+1)
                    mlc[i]=mlc[j]+1;
        int res=0;
        for(int i=0; i<n; i++)
            res=max(res,mlc[i]);
        return res;
    }
};