/*
 * @lc app=leetcode id=540 lang=cpp
 *
 * [540] Single Element in a Sorted Array
 */

// @lc code=start
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if (nums.size()==1)
        {
            return nums[0];
        }
        int l=0, r=nums.size()-1, mid;
        while (l < r)
        {
            mid = l+(r-l)/2;
            if ((mid%2==0 && nums[mid] == nums[mid+1]) || (mid%2==1 && nums[mid] == nums[mid-1]))
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

