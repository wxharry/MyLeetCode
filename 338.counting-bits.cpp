/*
 * @lc app=leetcode id=338 lang=cpp
 *
 * [338] Counting Bits
 */

// @lc code=start
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n+1, 0);
        for (int i = 1; i < n+1; ++i)
        {
            if (i & 1 == 1)
            {
                dp[i] = dp[i-1]+1;
            }
            else
            {
                dp[i] = dp[i>>1];
            }
        }
        return dp;
    }
};
// @lc code=end

