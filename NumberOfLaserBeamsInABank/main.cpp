class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int len = bank.size();
        int res;
        int prev = 0;
        for(int i = 0; i<len; i++){
            string str = bank[i];
            int sec = 0;
            for(auto ch:str)
                if(ch == '1')
                    sec += 1;
            if(sec != 0){
                res += prev*sec;
                prev = sec;
            }
        }
        return res;
    }
};