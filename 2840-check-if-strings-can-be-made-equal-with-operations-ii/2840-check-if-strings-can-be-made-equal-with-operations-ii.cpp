class Solution {
public:
    bool checkStrings(string s1, string s2) {
        unordered_map<char,int>mp1;
        unordered_map<char,int>mp2;
        for(int j=0; j<2; j++){
            for(int i=j; i<s1.size(); i+=2){
                mp1[s1[i]]++;
            }
            for(int i=j; i<s1.size(); i+=2){
                if(!mp1[s2[i]]--) return false;
            }
            mp1 = mp2;
        }
        return true;
    }
};