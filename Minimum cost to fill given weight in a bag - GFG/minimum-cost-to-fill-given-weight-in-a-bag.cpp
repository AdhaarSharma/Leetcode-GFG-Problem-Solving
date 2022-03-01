// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000
//Position this line where user code will be pasted.

class Solution{
	public:
	int minimumCost(int cost[], int N, int W) 
	{ 
        vector<int> dp(W+1,9999999);
        dp[0]=0;
        for(int i=1; i<=W; i++){
            for(int j=1; j<=i; j++){
                if(j<=N && cost[j-1]!=-1)
                    dp[i]=min(dp[i],cost[j-1]+dp[i-j]);
            }
        }
        return dp[W]==9999999?-1:dp[W];
	} 
};


// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, w;
        cin >> n >> w;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minimumCost(a, n, w) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends