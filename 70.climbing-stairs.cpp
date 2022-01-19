/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        return climbStairs2(n);
    }
    int climbStairs1(int n) {
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

    // faster dp
    int climbStairs2(int n) {
        int dp1 = 1, dp2 = 1, ans;
        for (int i = 2; i < n+1; ++i)
        {
            ans = dp1+dp2;
            dp1=dp2;
            dp2=ans;
        }
        return dp2;
    }
};
// @lc code=end

