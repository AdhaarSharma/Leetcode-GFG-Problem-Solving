class Solution {
public:
    bool isMatch(string s, string p) {
        
        bool dp[s.length()+1][p.length()+1];
        
        dp[0][0] = true;
        
        for( int i = 0 ;i <= s.length() ; i++ ){
            for( int j = 0 ; j <= p.length() ; j++ ){
                //exception if the first character of p is * then 
                if( i == 0 || j == 0 ){
                    if( i== 0 && j == 0 ){
                        continue;
                    }else if( j == 0 ){
                        dp[i][j] = false;
                    }else if( p[j-1] == '*' ){
                        dp[i][j] = dp[i][j-1];
                    }else{
                        dp[i][j] = false;
                    }
                }
                
                else if( p[j-1] == '*' ){
                    
                    if( dp[i-1][j] || dp[i][j-1] ){
                        dp[i][j] = true;
                    }else{
                        dp[i][j] = false;
                    }
                }else if( s[i-1] == p[j-1] || p[j-1] == '?'){
                    if( dp[i-1][j-1] ){
                        dp[i][j] = true;
                    }else{
                        dp[i][j] = false;
                    }
                }else{
                    
                    dp[i][j] = false;
                }
            }
        }
        
//         for( int i = 0 ;i <= s.length() ; i++ ){
//             for( int j = 0 ; j <= p.length() ; j++ ){
//                 cout << dp[i][j] << " ";
//             }
//             cout << endl;
//         }
        
        return dp[s.length()][p.length()];
        
    }
};