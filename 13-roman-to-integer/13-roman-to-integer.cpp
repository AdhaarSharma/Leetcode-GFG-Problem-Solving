class Solution {
public:
    int romanToInt(string s) {
        map<char,int> mp = {
            {'I',1}, {'V',5}, {'X',10}, {'L',50}, {'C',100}, {'D',500}, {'M',1000} 
        };
        int a=0;
        for(int i=0; i<s.length(); i++){
            if(mp[s[i]]<mp[s[i+1]]){
                a+=mp[s[i+1]]-mp[s[i]];
                i++;
            } else {
                a+=mp[s[i]];
            }
        }
        return a;
    }
};