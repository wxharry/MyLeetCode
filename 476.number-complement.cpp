/*
 * @lc app=leetcode id=476 lang=cpp
 *
 * [476] Number Complement
 */

// @lc code=start
class Solution {
public:
    int findComplement(int num) {
        int i=1;
        int temp = num;
        while (num != 1)
        {
            num >>= 1;
            ++i;
        }
        printf("i=%d\n", i);
        return pow(2, i)-1 -temp;
    }
};
// @lc code=end

