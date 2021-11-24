/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 */

// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> res(n, 1);
        vector<int> l2r(res), r2l(res);
        for (int i = 1; i < n; ++i)
        {
            l2r[i] = nums[i-1] * l2r[i-1];
        }
        for (int i = n-2; i >= 0; --i)
        {
            r2l[i] = nums[i+1] * r2l[i+1];
        }
        for (int i = 0; i < n; ++i)
        {
            res[i] = l2r[i] * r2l[i];
        }
        return res;
    }
};
// @lc code=end

