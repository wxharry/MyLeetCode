/*
 * @lc app=leetcode id=461 lang=cpp
 *
 * [461] Hamming Distance
 */

// @lc code=start
class Solution {
public:
    int hammingDistance(int x, int y) {
        int diff = x^y, ans = 0;
        while (diff)
        {
            ans += diff &1;
            diff >>= 1;
        }
        return ans;
    }
};
// @lc code=end

