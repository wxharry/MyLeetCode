/*
 * @lc app=leetcode id=154 lang=cpp
 *
 * [154] Find Minimum in Rotated Sorted Array II
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0, r=nums.size()-1, mid;
        while (l != r)
        {
            mid = l + (r-l)/2;
            if (nums[mid] == nums[r])
            {
                --r;
            }
            else if (nums[mid] > nums[r])
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }
        return nums[l];        
    }
};
// @lc code=end

