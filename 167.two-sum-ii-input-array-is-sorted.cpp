/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input array is sorted
 */

// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int n = numbers.size();
        int l = 0;
        int r = n - 1;
        int sum;
        while (l < r)
        {
            sum = numbers[l] + numbers[r];
            if (sum == target)
            {
                break;
            }
            else if (sum > target)
            {
                --r;
            }
            else
            {
                ++l;
            }
        }

        return vector<int>{++l, ++r};
    }
};
// @lc code=end
