/*
 * @lc app=leetcode id=204 lang=cpp
 *
 * [204] Count Primes
 */

// @lc code=start
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> lit(n, true);
        if(n < 2) return 0;
        int res=n-2;
        lit[0] = lit[1] = false;
        for (int i = 2; i < n; ++i)
        {
            for (int j = 2; j*i < n; ++j)
            {
                if (lit[j*i])
                {
                    lit[j*i] = false;
                    --res;
                }
            }
        }
        return res;
    }
};
// @lc code=end

