/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res, count=0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (count == 0)
            {
                res = nums[i];
            }
            if (nums[i] == res)
            {
                ++ count;
            }
            else if (nums[i] != res)
            {
                -- count;
            }
            
            
        }
        return res;
    }
};
// @lc code=end

