class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        if(s.back() == '1') return false;
        s[0] = '2';
        int j = 0;
        for(int i = 0; i<s.size() && s.back() != '2'; i++){
            if(s[i] != '2') continue;
            j = max(j, i + minJump);
            while(j<s.size() && maxJump>=j-i){
                if(s[j] == '0') s[j] = '2';
                j++;
            }
        }
        return s.back() == '2';
    }
};