/*
 * @lc app=leetcode id=665 lang=cpp
 *
 * [665] Non-decreasing Array
 */

// @lc code=start
class Solution
{
public:
    bool checkPossibility(vector<int> &nums)
    {
        int count = 0;
        int n = nums.size();
        for (int i = 0; i < nums.size()-1; ++i)
        {
            if (nums[i] > nums[i+1])
            {
                if (i==0 || (i > 0 && nums[i+1] >= nums[i-1]))
                {
                    nums[i] = nums[i+1];
                    ++count;
                }
                else if( nums[i+1] < nums[i-1])
                {
                    nums[i+1] = nums[i];
                    ++count;
                }    
                if (count==2)
                {
                    return false;
                }
                
            }
            
        }
        return true;
        
    }
};
// @lc code=end
