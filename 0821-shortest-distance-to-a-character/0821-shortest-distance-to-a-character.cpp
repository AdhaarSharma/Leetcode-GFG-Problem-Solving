class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.length();
        vector<int>left(n, INT_MAX), right(n, INT_MAX);
        bool left1 = false, right1 = false;
        for(int i=0; i<n; i++){
            if(s[i] == c) left[i] = 0, left1 = true;
            else if(left1 == true) left[i] = left[i-1] + 1;
            if(s[n-i-1] == c) right[n-i-1] = 0, right1 = true;
            else if(right1 == true) right[n-i-1] = right[n-i] + 1;
        }
        vector<int> ans(n,INT_MAX);
        for(int i=0; i<n; i++){
            ans[i] = min(left[i], right[i]);
        }
        return ans;
    }
};