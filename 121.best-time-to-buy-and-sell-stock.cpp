/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
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
};
// @lc code=end

