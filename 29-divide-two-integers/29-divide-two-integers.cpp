class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        long long _dividend = dividend;
        long long _divisor = divisor;
        
        int sign = ((_dividend < 0) ^
                    (_divisor < 0)) ? -1 : 1;
        cout << sign << endl;
        _dividend = abs(_dividend);
        _divisor = abs(_divisor);

        long long quotient = 0, temp = 0;

        for (int i = 31; i >= 0; --i) {

            if (temp + (_divisor << i) <= _dividend) {
                temp += _divisor << i;
                quotient |= 1LL << i;
            }
        }
        return quotient*sign;
    }
};