class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int bestbuy = prices[0], maxprofit = 0;
        for(int x : prices) {
            if(x > bestbuy) {
                maxprofit = max(maxprofit, x - bestbuy);
            }
            else bestbuy = x;
        }
        return maxprofit;
    }
};
