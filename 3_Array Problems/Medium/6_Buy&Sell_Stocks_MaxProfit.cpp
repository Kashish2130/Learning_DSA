//?You are given an array prices where prices[i] is the price of a given stock on the ith day.

//You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

//Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

//ex : [7,1,5,3,6,4]

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