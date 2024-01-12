class Solution {
public:
    bool halvesAreAlike(string s) {
        vector<char> v={'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        set<char> s1;
        s1.insert(v.begin(),v.end());
        int n = s.length(), cnt1=0, cnt2=0;
        for(int i=0; i<n/2; i++){
            if(s1.find(s[i]) != s1.end()) cnt1++;
            if(s1.find(s[n-i-1]) != s1.end()) cnt2++;
        }
        return cnt1 == cnt2;
    }
};