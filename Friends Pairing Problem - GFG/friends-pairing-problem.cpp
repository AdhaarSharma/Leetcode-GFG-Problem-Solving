// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    int countFriendsPairings(int n) { 
        int mod=1e9+7;
        int a = 1, b = 2, c = 0;
        if (n <= 2) {
            return n;
        }
        for (long long int i = 3; i <= n; i++) {
            c=(b+(i-1)*a)%mod;
            a=b;
            b=c;
        }
        return c;
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