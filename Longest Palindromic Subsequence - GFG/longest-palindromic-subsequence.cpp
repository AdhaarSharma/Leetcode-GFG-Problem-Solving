// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int dp[1000][1000];
    int longestPalinSubseq(string A) {
        memset(dp,-1,sizeof(dp));
        return dp[0][A.length()] = lps(A, 0, A.length());
    }
    int lps(string A, int i, int j){
        if(i==j)
            return 1;
        if(dp[i][j] != -1)
            return dp[i][j];
        if(A[i]==A[j] && i+1==j)
            return dp[i][j] = 2;
        else if(A[i]==A[j])
            return dp[i][j] = 2+lps(A,i+1,j-1);
        else
            return dp[i][j] = max(lps(A,i+1,j),lps(A,i,j-1));
    }
};

// { Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends