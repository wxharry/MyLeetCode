/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l=0, r=nums.size(), mid;
        vector <int> result;
        while (l < r)
        {
            mid = l + (r-l)/2;
            if (nums[mid] >= target)
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }                      
        }
        result.push_back(l);
        l=0; r=nums.size();
        while (l < r)
        {
            mid = l + (r-l)/2;
            if (nums[mid] <= target)
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }
        result.push_back(l-1);
        if (result[0] == nums.size() || nums[result[0]] != target)
        {
            return vector<int> {-1, -1};
        }
        return result;            
    }
};
// @lc code=end

