class Solution {
public:
    vector<int> countBits(int num) {
        //mem[i] = No of 1s from 0 to number i
        vector<int> mem(num+1);
        mem[0] = 0;
        
        for(int i=1;i<=num;++i)
            mem[i] = mem[i/2] + i%2;
        
        return mem;
    }
};