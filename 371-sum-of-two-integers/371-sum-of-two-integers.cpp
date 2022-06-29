class Solution {
public:
    int getSum(int a, int b) {
        return b==0 ? a:getSum(a^b, (a&b&0xffffffff)<<1);
    }
};