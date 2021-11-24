/*
 * @lc app=leetcode id=162 lang=cpp
 *
 * [162] Find Peak Element
 */

// @lc code=start
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int peak=0;    
        int n = nums.size();
        if (n < 2)
        {
            return peak;
        }
        for (int i = 0; i < n; ++i)
        {
            if (i == 0 && nums[0] > nums[1] || i == n-1 && nums[n-1] > nums[n-2] || i < n-1 && nums[i]-nums[i+1]>0 && i > 0 && nums[i]-nums[i-1] > 0)
            {
                peak = i;
                break;
            }
            
        }
        return peak;
    }
};
// @lc code=end

