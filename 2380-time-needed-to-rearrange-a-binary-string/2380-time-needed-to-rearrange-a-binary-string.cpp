class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int n = s.size(), ans = 0;
        while(1)
        {
            vector<int> v;
            for(int i = 0; i < n-1; i++)
            {
                if(s[i] == '0' && s[i+1] == '1') v.push_back(i);
            }
            int len = v.size();
            if(!len) return ans;
            for(int i = 0; i < len; i++)
            {
                swap(s[v[i]], s[v[i]+1]);
            }
            ans += 1;
        }
        return ans;
    }
};