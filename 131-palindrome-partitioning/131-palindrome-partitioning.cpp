class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> path;
        part(s,0,path,result);
        return result;
    }
private:
    void part(string &s, int start, vector<string>&path, vector<vector<string>>&result){
        int n = s.size();
        if(start == n)
            result.push_back(path);
        else{
            for(int i=start; i<n; i++){
                if(isPalindrome(s,start,i)){
                    path.push_back(s.substr(start,i-start+1));
                    part(s,i+1,path,result);
                    path.pop_back();
                }
            }
        }
    }
    bool isPalindrome(string &s, int left, int right){
        while(left<right){
            if(s[left++]!=s[right--])
                return false;
        }
        return true;
    }
    
};