/*
 * @lc app=leetcode id=81 lang=cpp
 *
 * [81] Search in Rotated Sorted Array II
 */

// @lc code=start
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l=0, r=nums.size()-1, mid;
        while (l <= r)
        {
            mid = l + (r-l)/2;
            if (nums[mid] == target)
            {
                return true;
            }
            if (nums[mid] == nums[r])
            {
                --r;
            }
            else if (nums[mid] < nums[r])
            {
                if (target > nums[mid] && target <= nums[r])
                {
                    l = mid + 1;
                }
                else
                {
                    r = mid;
                }
                
                
            }
            else
            {
                if (target < nums[mid] && target >= nums[l] )
                {
                    r = mid;
                }
                else
                {
                    l = mid + 1;
                }
                
                
            }
            
            
            
        }
            return false;
        
    }
};
// @lc code=end

