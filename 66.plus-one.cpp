/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 */

// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(), digits.end());
        int addUnit=0;
        int res = digits[0] + 1 + addUnit;
        addUnit = res/10;
        digits[0] = res%10;
        
        for (int i = 1; i < digits.size(); i++)
        {
            res = digits[i] + addUnit;
            addUnit = res/10;
            digits[i] = res%10;
        }
        if (addUnit)
        {
            digits.push_back(1);
        }
        reverse(digits.begin(), digits.end());
        return digits;
    }
};
// @lc code=end

