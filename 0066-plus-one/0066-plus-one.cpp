class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i;
        for(i=digits.size()-1; i>=0; i--){
            if(digits[i]!=9){
                digits[i]++;
                break;
            }
            digits[i] = 0;
        }
        if(i == -1) digits.push_back(0), digits[0] = 1;
        return digits;
    }
};