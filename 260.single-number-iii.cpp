/*
 * @lc app=leetcode id=260 lang=cpp
 *
 * [260] Single Number III
 */

// @lc code=start
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long intxor=0;
        for (auto &&num : nums)
        {
            intxor ^= num;
        }
        int diff = (-intxor) & intxor;
        int a=0, b=0;
        for (auto &&num : nums)
        {
            if (num&diff)
            {
                a ^= num;
            }
            else
            {
                b ^= num;
            }
            
        }
        return vector<int> {a, b};

    }
};
// @lc code=end

