/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        return rob4(nums);
    }
    int rob1(vector<int>& nums) {
        if(nums.empty()) return 0;
        int n = nums.size();
        vector<int> dp(n+1, 0);
        dp[1] = nums[0];
        for (int i = 2; i < n+1; ++i)
        {
            dp[i] = max (dp[i-1], dp[i-2] + nums[i-1]);
        }
        return dp[n];
    }

    int rob2(vector<int>& nums){
        int n=nums.size();
        vector<int> dp(n+1, 0);
        dp[0] = 0;
        dp[1] = nums[0];
        for (int i = 2; i < n+1; ++i){
            dp[i] = max(dp[i-2]+nums[i-1], dp[i-1]);
        }
        return dp[n];
    }

    // runtime beats 100%
    // memory usage beats over 70%
    int rob3(vector<int>& nums){
        int n=nums.size();
        int rob=0;
        int skip=0;
        for (int i = 0; i < n; ++i)
        {
            int last_skip = skip;
            skip = max(skip, rob + nums[i]);
            rob = last_skip;
        }
        return max(rob, skip);
    }

    // runtime beats 100%
    // memory usage beats over 70%
    // better code implemented according to state transition
    int rob4(vector<int>& nums){
        int n=nums.size();
        int rob=0;
        int skip=0;
        for (int i = 0; i < n; ++i)
        {
            int last_skip = skip;
            skip = max(skip, rob);
            rob = last_skip + nums[i];
        }
        return max(rob, skip);
    }
};
// @lc code=end

