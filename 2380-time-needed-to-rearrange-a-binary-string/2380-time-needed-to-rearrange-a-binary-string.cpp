class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int ans = 0;
        int num1 = 0;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '1') {
                if(ans > 0) {ans = max(i - num1, ans + 1);}
                else {ans = i - num1;}
                num1++;
            }
        }
        return ans;
    }
};