/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 */

// @lc code=start
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int m = nums.size(), n=accumulate(nums.begin(), nums.end(), 0);
        if(n < abs(target)) return 0;
        vector<vector<int>> dp(m+1, vector<int> (n+1, 0));
        
        dp[0][0]=1;
        for (int i = 1; i < m+1; ++i)
        {
            for (int j = 0; j < n+1; ++j)
            {
                dp[i][j] += dp[i-1][abs(j-nums[i-1])];
                if (j+nums[i-1] <= n)
                {
                    dp[i][j] += dp[i-1][j+nums[i-1]];
                }
            }
        }
        return dp[m][abs(target)];
        
    }
};
// @lc code=end

