/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
 */

// @lc code=start
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = nums.size();
        int i=0;
        for (auto &&num : nums)
        {
            res ^= num;
            res ^= i;
            ++i;
        }
        return res;
    }
};
// @lc code=end

