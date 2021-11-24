/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int res=INT_MIN;
        vector<int> dp(n+1, 0);
        for (int i = 1; i < n+1; ++i)
        {
            if (dp[i-1] < 0)
            {
                dp[i] = nums[i-1];
            }
            else
            {
                dp[i] = nums[i-1]+dp[i-1];
            }
            res = max(res, dp[i]);
        }
        return res;        
    }
};
// @lc code=end

