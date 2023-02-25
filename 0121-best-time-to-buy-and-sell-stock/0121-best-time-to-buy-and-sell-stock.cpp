class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0, minPrice = INT_MAX;
        for(auto p : prices){
            if(p < minPrice) minPrice = p;
            maxProfit = max(maxProfit, p - minPrice);
        }
        return maxProfit;
    }
};