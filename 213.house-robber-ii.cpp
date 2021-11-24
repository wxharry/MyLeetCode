/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==2) return max(nums[0], nums[1]);
        if(n==1) return nums[0];
        if(n==0) return 0;
        vector<int>dp1(n+1), dpn(n+1);
        dp1[0] = 0;dp1[1]=nums[0];
        for (int i = 2; i < n; ++i)
        {
            dp1[i] = max(dp1[i-1], dp1[i-2]+nums[i-1]);
        }
        dpn[0] = dpn[1]=0;
        dpn[2] = nums[1];
        for (int i = 3; i < n+1; ++i)
        {
            dpn[i] = max(dpn[i-1], dpn[i-2]+nums[i-1]);
        }
        return max(dp1[n-1], dpn[n]);
    }
};
// @lc code=end

