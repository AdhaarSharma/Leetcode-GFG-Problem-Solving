class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> cnt(256, 0);
        int count = 0;
        int start = 0;
        int ans = INT_MAX;
        for(auto ch:t){
            if(cnt[ch] == 0)
                count++;
            cnt[ch]++;
        }
        int i=0, j=0;
        while(j<s.length()){
            cnt[s[j]]--;
            if(cnt[s[j]] == 0)
                count--;
            if(count == 0){
                while(count == 0){
                    if(ans > j-i+1){
                        ans = j-i+1;
                        start = i;
                    }
                    cnt[s[i]]++;
                    if(cnt[s[i]] > 0)
                        count++;
                    i++;
                }
            }
            j++;
        }
        if(ans == INT_MAX)
            return "";
        else
            return s.substr(start, ans);
    }
};