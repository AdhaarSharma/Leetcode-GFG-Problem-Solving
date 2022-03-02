// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++
class Solution{   
public:
   //vector <vector<int>> dp ;
    int dp[100][10000] ;
   bool isSubsetSum(int n, int arr[], int sum)   // n is no of element in a[]
   {
       //dp.resize(n+1,vector<int>(sum+1,-1)) ;
       memset(dp,-1,sizeof(dp)) ;
      return subsum (n,arr,sum) ;
   }   
       
   int subsum (int n, int a[], int sum)
   {
       if (sum == 0)
         return 1 ;
         
       if (n<=0 or sum<0)
          return 0 ;
          
       if (dp[n-1][sum] != -1)   
          return dp[n-1][sum] ;
          
       if (a[n-1] > sum)
          return dp[n-1][sum] = subsum (n-1,a,sum) ;
          
       return dp[n-1][sum] = subsum (n-1,a,sum) || subsum (n-1,a,sum-a[n-1]) ;
   }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(N, arr, sum) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends