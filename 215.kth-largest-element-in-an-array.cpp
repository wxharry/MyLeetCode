/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */

// @lc code=start
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        for (int i = 0; i < k; ++i)
        {
            for (int j = 0; j < nums.size() - i -1; ++j)
            {
                if (nums[j] > nums[j+1])
                {
                    int temp = nums[j];
                    nums[j] = nums[j+1];
                    nums[j+1] = temp;
                }
                
            }
            
        }
        return nums[nums.size()-k];
        
    }
};
// @lc code=end

