/*
 * @lc app=leetcode id=633 lang=cpp
 *
 * [633] Sum of Square Numbers
 */

// @lc code=start
class Solution {
public:
    bool judgeSquareSum(int c) {
        long a=0, b = (int)sqrt(c);
        while (a <= b)
        {
            if (a*a+b*b == c)
            {
                return true;
            }
            else if (a*a+b*b < c)
            {
                ++a;
            }
            else
            {
                --b;
            }
        }
        return false;        
    }
};
// @lc code=end

