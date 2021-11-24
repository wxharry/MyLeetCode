/*
 * @lc app=leetcode id=448 lang=cpp
 *
 * [448] Find All Numbers Disappeared in an Array
 */

// @lc code=start
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i < n; ++i)
        {
            int idx = abs(nums[i])-1;
            if(nums[idx] > 0) nums[idx] = -nums[idx];
        }
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] > 0)
            {
                ans.push_back(i+1);
            }
            
        }
        return ans;
        
    }
};
// @lc code=end

