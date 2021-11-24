/*
 * @lc app=leetcode id=309 lang=cpp
 *
 * [309] Best Time to Buy and Sell Stock with Cooldown
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n<2) return 0;
        vector<int> s0(n+1), s1(n+1), s2(n+1);
        s0[0]=0;
        s1[0]=-prices[0];
        s2[0]=INT_MIN;
        for (int i = 1; i < n+1; ++i)
        {
            s0[i] = max(s0[i-1], s2[i-1]);
            s1[i] = max(s1[i-1], s0[i-1] - prices[i-1]);
            s2[i] = s1[i-1] + prices[i-1];
        }
        return max(s2[n], s0[n]);
    }
};
// @lc code=end

