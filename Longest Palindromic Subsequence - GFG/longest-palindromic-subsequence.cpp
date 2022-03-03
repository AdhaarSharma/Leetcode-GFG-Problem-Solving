// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int longestPalinSubseq(string A) {
        int n = A.length();
        int dp[n+1][n+1];
        for(int i=0; i<=n; i++)
            dp[i][i] = 1;
        for(int len=2; len<=n; len++){
            for(int i=0; i<n-len+1; i++){
                int j=i+len-1;
                if(A[i]==A[j] && i+1==j)
                    dp[i][j]=2;
                else if(A[i]==A[j])
                    dp[i][j] = 2+dp[i+1][j-1];
                else
                    dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
            }
        }
        return dp[0][n-1];
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