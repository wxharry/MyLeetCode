/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return maxSubArray2(nums);
    }
    int maxSubArray1(vector<int>& nums) {
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
    
    // second trial
    int maxSubArray2(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;
        vector<int> dp(n+1, 0);
        for (int i = 1; i < n+1; ++i)
        {
            // we update the maximum sum of subarray which ends at i-1
            dp[i] = max(nums[i-1], dp[i-1] + nums[i-1]);
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
// @lc code=end

