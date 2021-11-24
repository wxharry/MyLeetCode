/*
 * @lc app=leetcode id=693 lang=cpp
 *
 * [693] Binary Number with Alternating Bits
 */

// @lc code=start
class Solution {
public:
    bool hasAlternatingBits(int n) {
        long foo = (n ^ (n >> 1));
        return  (foo&(foo+1)) == 0;
    }
};
// @lc code=end

