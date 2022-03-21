class Solution {
public:
    int longestValidParentheses(string s) 
    {
        if(s.length()==0)
            return 0;
        if(s == "()")
            return 2;
        
        // The real solution
        int count = 0;
        int maxLength = 0;
        
        for(int i=0;i<s.length();i++)
        {
            count = 0;
            for(int j=i;j<s.length();j++)
            {
                if(s[j] == '(')
                    count++;
                else
                    count--;
                
                if(count<0)
                    break;
                
                if(count == 0)
                    maxLength = max(maxLength,j-i+1);
            }
        }
        
        return maxLength;
    }
    
};