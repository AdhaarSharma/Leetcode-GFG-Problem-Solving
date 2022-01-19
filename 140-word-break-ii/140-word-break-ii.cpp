class Solution {
    unordered_map<string,vector<string>> dp;
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        if(dp.find(s) != dp.end()) return dp[s];
        vector<string> result;
        for(auto w:wordDict){
            if(s.substr(0,w.length())==w)
                if(s.length() == w.length())
                    result.push_back(w);
                else{
                    vector<string>temp = wordBreak(s.substr(w.length()),wordDict);
                    for(auto t:temp)
                        result.push_back(w + " " + t);
                }
        }
        return dp[s] = result;
    }
};