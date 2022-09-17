class Solution {
public:
    int minGroups(vector<vector<int>>& in) {
        
        int n = in.size();
        
        int s[n],e[n];
        
        for(int i=0;i<n;i++) {
            s[i] = in[i][0];
            e[i] = in[i][1];
        }
        
        sort(s,s+n);
        sort(e,e+n);
        
        int req = 1,ans = 1,j = 0,i = 1;
        
        while(i<n and j<n){
            if(s[i]<=e[j]){
                req++;
                i++;
            }else{
                req--;
                j++;
            }
            
            ans = max(ans,req);
        }
        
        return ans;
    }
};