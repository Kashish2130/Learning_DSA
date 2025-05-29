class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;
        int profit = 0;
        for (auto price : prices) {
            if (price < minPrice) {
                minPrice = price;
            }

            profit = price - minPrice;
            maxProfit = max(profit, maxProfit);
        }
        return maxProfit;
    }
};