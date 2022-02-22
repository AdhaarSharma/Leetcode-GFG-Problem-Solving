// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    int countFriendsPairings(int n) 
    { 
        int dp[n+1]{0};
        int m=1e9+7;
        dp[1]=1;
        dp[2]=2;
        for(long long int i=3; i<=n; i++){
            dp[i] = (dp[i-1]+(i-1)*dp[i-2])%m;
        }
        return dp[n]%m;
    }
};    
 

// { Driver Code Starts.
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 
  // } Driver Code Ends