/*
 * @lc app=leetcode id=227 lang=cpp
 *
 * [227] Basic Calculator II
 */

// @lc code=start
class Solution {
public:
    int calculate(string s) {
        stringstream ss("+"+s);
        int n, ans=0, last;
        char op;
        while (ss >> op >> n)
        {
            if (op == '+' || op == '-')
            {
                n = op=='+'? n: -n;
                ans += n;
            }
            else
            {
                n = op=='*' ? last*n: last/n;
                ans = ans-last + n;
            }
            last = n;
        }
        return ans;        
    }
};
// @lc code=end

