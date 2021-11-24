/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int res = 1;
        vector<int> dp(n+1, 1);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (nums[i] > nums[j])
                {
                    dp[i] = max(dp[j] + 1, dp[i]);
                }
                
            }
            res = max(dp[i], res);
        }
        return res;
    }
};
// @lc code=end

