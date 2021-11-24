/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int hold = 0;
        int profit = 0;
        int i;
        for (i = 0; i < prices.size() - 1; i++)
        {
           
            if (prices[i] > prices[i+1])
            {
                profit += prices[i] - prices[hold];
                hold = i + 1;
            }
            
        }
        profit += prices[i] - prices[hold];
        return profit;
    }
};
// @lc code=end

