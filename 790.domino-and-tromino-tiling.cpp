/*
 * @lc app=leetcode id=790 lang=cpp
 *
 * [790] Domino and Tromino Tiling
 */

// @lc code=start
class Solution {
    int kmod = 1000000007;
public:
    int numTilings(int n) {
        vector<long> s0(n+1, 0), s1(n+1, 0), s2(n+1, 0);
        s0[0] = 1; s1[0] = 0; s2[0] = 0;
        s0[1] = 1; s1[1] = 0; s2[1] = 0;
        for (int i = 2; i < n+1; ++i)
        {
            s0[i] = (s0[i-1] + s0[i-2] + s1[i-1] + s2[i-1]) % kmod;
            s1[i] = (s0[i-2] + s2[i-1]) % kmod;
            s2[i] = (s0[i-2] + s1[i-1]) % kmod;
        }
        return s0[n] ;
    }
};
// @lc code=end

