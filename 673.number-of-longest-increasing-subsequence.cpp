/*
 * @lc app=leetcode id=673 lang=cpp
 *
 * [673] Number of Longest Increasing Subsequence
 */

// @lc code=start
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 1;
        vector<int> dp(n, 1), dpn(n, 1);
        for (int i = 1; i < n; ++i)
        {
            for (int j = i - 1; j >= 0; --j)
            {
                if (nums[i] > nums[j])
                {
                    if (dp[i] < dp[j] + 1)
                    {
                        dp[i] = dp[j] + 1;
                        dpn[i] = dpn[j];
                    }
                    else if (dp[i] == dp[j] + 1)
                    { 
                        dpn[i] += dpn[j];
                    }
                    
                }
            }        
            maxLen = max(maxLen, dp[i]);    
        }
        int ans=0;
        for (int i = 0; i < n; ++i){
            if (dp[i] == maxLen){
                ans += dpn[i];
            }
        }
        return ans;
    }
};
// @lc code=end

