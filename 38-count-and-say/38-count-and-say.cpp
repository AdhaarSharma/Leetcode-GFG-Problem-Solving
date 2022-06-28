class Solution {
public:
    string countAndSay(int n) {
        string say = "1";
        string tmp = "";
        
        for (int i = 1; i < n; i++) {
            // Base case
            int count = 1;
            char prev = say[0];
            
            // Iterate starting with the second digit since
            // base case has already been set
            for (int j = 1; j < say.length(); j++) {
                // If the current and previous digits are different
                if (say[j] != prev) {
                    // Add the count and digit to the tmp buffer
                    tmp += (char)count + '0';
                    tmp += prev;
                    
                    // Reset count to 0 to prepare for counting a new digit
                    count = 0;
                }
                
                count++;
                prev = say[j];
            }
            
            // Add the count and digit to the tmp buffer for the last digit
            tmp += (char)count + '0';
            tmp += prev;
            
            // Say represents the output of this iteration of n
            say = tmp;
            tmp = "";
        }
        
        return say;
    }
};