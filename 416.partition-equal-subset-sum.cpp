/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 */

// @lc code=start
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum%2) return false;
        sum /=2;
        vector<vector<bool>> dp(n+1, vector<bool>(sum+1 , false));
        dp[0][0] = true;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= sum; ++j)
            {
                if (nums[i-1] > j)
                {
                    dp[i][j] = dp[i-1][j];
                }
                else
                {
                    dp[i][j] = dp[i-1][j] | dp[i-1][j-nums[i-1]];
                }
                
                
            }
            
        }
        return dp[n][sum];
    }
};
// @lc code=end

