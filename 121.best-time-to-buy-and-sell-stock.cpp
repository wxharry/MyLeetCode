/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        return maxProfit2(prices);
    }
    int maxProfit1(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(n+1, 0);
        int min_buy = prices[0];
        int max_profit = 0;
        for (int i = 1; i < n+1; ++i)
        {
            max_profit = max(prices[i-1] - min_buy, max_profit);
            dp[i] = max_profit;
            min_buy = min(min_buy, prices[i-1]);
        }
        return max_profit;
    }
    // least spaces used
    int maxProfit2(vector<int>& prices) {
        int n = prices.size();
        int cost=prices[0], profit=0;
        for (int i = 1; i < n; ++i)
        {
            profit = max(profit, prices[i] - cost);
            cost = min(cost, prices[i]);
        }
        return profit;
    }
    // ideas from Huahua
    int maxProfit3(vector<int>& prices){
        int n = prices.size();
        vector<int> min_prices(n, 0);
        vector<int> max_profit(n, 0);
        min_prices[0] = prices[0];
        for (int i = 1; i < n; ++i)
        {
            min_prices[i] = min(min_prices[i-1], prices[i]);
            max_profit[i] = max(max_profit[i-1], prices[i] - min_prices[i-1]);
        }
        return max_profit[n-1];
    }
};
// @lc code=end

