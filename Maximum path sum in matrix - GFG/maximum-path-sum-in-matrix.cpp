// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        int dp[N+1][N+1];
        memset(dp,0,sizeof(dp));
        for (int j = 0; j < N; j++)
            dp[0][j] = Matrix[0][j];
        for(int i=1; i<N; i++){
            for(int j=0; j<N; j++){
                if(j>0 && j<N-1)
                    dp[i][j]+=max(dp[i-1][j],max(dp[i-1][j+1],dp[i-1][j-1]))+Matrix[i][j];
                else if(j>0)
                    dp[i][j]+=max(dp[i-1][j],dp[i-1][j-1])+Matrix[i][j];
                else if(j<N-1)
                    dp[i][j]+=max(dp[i-1][j],dp[i-1][j+1])+Matrix[i][j];
            }
        }
        int res = 0;
        for (int j = 0; j < N; j++)
            res = max(dp[N-1][j], res);
        return res;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}  // } Driver Code Ends