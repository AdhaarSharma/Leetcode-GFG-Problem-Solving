class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        if (s.back() == '1') return false;
        s[0] = '2'; // mark s[0] as reacheable
        int j = 0;
        for (int i = 0; i < s.size() && s.back() != '2'; ++i) {
            if (s[i] != '2') continue; // only extend reacheable points
            j = max(j, i + minJump); // `j` is at least `i + minJump`
            while (j < s.size() && j - i <= maxJump) { // try to extend until `j > i + maxJump`
                if (s[j] == '0') s[j] = '2'; // mark `s[j]` as reacheable if `s[j] == '0'`
                ++j;
            }
        }
        return s.back() == '2';
    }
};