class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        long long number=0;
        int a = x;
        while(x!=0){
            number = number*10 + x%10;
            x = x/10;
        }
        if(number == a)
            return true;
        return false;
    }
};