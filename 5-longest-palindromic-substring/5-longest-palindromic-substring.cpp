class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        bool dp[n][n];
        memset(dp, false, sizeof(dp));
        int maxLength = 1;
        int start = 0;
        for(int i=0; i<n; i++)
            dp[i][i] = true;
        for(int i=0; i<n-1; i++){
            if(s[i] == s[i+1]){
                dp[i][i+1] = true;
                start = i;
                maxLength = 2;
            }
        }
        for(int len=3; len<=n;len++){
            for(int j=0; j<n-len+1; j++){
                int k = j+len-1;
                if(s[j] == s[k] && dp[j+1][k-1]){
                    dp[j][k] = true;
                    if(len>maxLength){
                        start = j;
                        maxLength = len;
                    }
                }
            }
        }
        return s.substr(start,maxLength);
    }
};