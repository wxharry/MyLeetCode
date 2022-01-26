/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        return lengthOfLIS2(nums);
    }
    int lengthOfLIS1(vector<int>& nums) {
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
    int lengthOfLIS2(vector<int>& nums) {
        int n = nums.size();
        int ans=1;
        vector<int> dp(n, 1);
        dp[0] = 1;
        for (int i = 1; i < n; ++i)
        {
            for (int j = i-1; j >= 0; --j)
            {
                if (nums[i] > nums[j])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
// @lc code=end

