/*
 * @lc app=leetcode id=168 lang=cpp
 *
 * [168] Excel Sheet Column Title
 */

// @lc code=start
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res;
        while (columnNumber>0)
        {
            int foo = (columnNumber-1)%26;
            char c = 'A' + foo;
            res = c + res;
            columnNumber = (columnNumber-1)/ 26;
        }
        return res;
    }
};
// @lc code=end

