/*
 * @lc app=leetcode id=342 lang=cpp
 *
 * [342] Power of Four
 */

// @lc code=start
class Solution {
public:
    bool isPowerOfFour(int n) {
        if(!n) return false;
        while (n)
        {
            cout << n%4 << endl;
            if (n%4 && n != 1)
            {
                return false;
            }
            n/=4;
        }
        return true;
    }
};
// @lc code=end

