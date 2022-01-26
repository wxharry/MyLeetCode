/*
 * @lc app=leetcode id=96 lang=cpp
 *
 * [96] Unique Binary Search Trees
 */

// @lc code=start
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        for (int i = 1; i < n+1; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                // we can split the tree into one root and two children and count possible number of each children then add up.
                dp[i] += dp[j] * dp[i-1-j];
            }
        }
        return dp[n];
    }
};
// @lc code=end

