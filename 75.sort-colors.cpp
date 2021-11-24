/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector <int> temp(nums.size());
        int r=0, w=0, b=0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == 0)
            {
                temp[b++] = 2;
                temp[w++] = 1;
                temp[r++] = 0;
            }
            else if (nums[i] == 1)
            {
                temp[b++] = 2;
                temp[w++] = 1;
            }
            else
            {
                temp[b++] = 2;
            }
        }
        nums = temp;         
    }
};
// @lc code=end

