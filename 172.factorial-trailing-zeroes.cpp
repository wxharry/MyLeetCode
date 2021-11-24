/*
 * @lc app=leetcode id=172 lang=cpp
 *
 * [172] Factorial Trailing Zeroes
 */

// @lc code=start
class Solution {
public:
    int trailingZeroes(int n) {
        return n==0?n:trailingZeroes(n/5) + n/5;
    }
};
// @lc code=end

