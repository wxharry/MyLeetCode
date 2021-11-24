/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        if (n < 3)
        {
            return n;
        }
        vector<int> dp(n+1, 1);
        for (size_t i = 2; i < n+1; ++i)
        {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
        
    }
};
// @lc code=end

