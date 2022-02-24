class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.length(), len2 = text2.length();
        return len1>len2?LCS(text1, text2):LCS(text2, text1);
    }
    int LCS(string text1, string text2){
        int len1 = text1.length(), len2 = text2.length();
        int dp[2][len2+1];
        memset(dp,0,sizeof(dp));
        for(int i = 0; i<=len1; i++)
            for(int j = 0; j<=len2; j++){
                if(i == 0 || j == 0)
                    dp[i%2][j] = 0;
                else if(text1[i-1] == text2[j-1])
                    dp[i%2][j] = 1+dp[(i+1)%2][j-1];
                else
                    dp[i%2][j] = max(dp[(i+1)%2][j], dp[i%2][j-1]);
            }
        return dp[len1%2][len2];
    }
};