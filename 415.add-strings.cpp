/*
 * @lc app=leetcode id=415 lang=cpp
 *
 * [415] Add Strings
 */

// @lc code=start
class Solution {
public:
    string addStrings(string num1, string num2) {
        if(num1.size() > num2.size()) return addStrings(num2, num1);
        int m=num1.size(), n=num2.size();
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        string res;
        int addbit = 0;
        for (int i = 0; i < m; ++i)
        {
            int foo = num1[i]-'0' + num2[i]-'0' + addbit;
            res += to_string(foo%10);
            addbit = foo/10;
        }
        for (int i = m; i < n; ++i)
        {
            int foo = num2[i]-'0' + addbit;
            res += to_string(foo%10);
            addbit = foo/10;
        }
        if (addbit)
        {
            res+="1";
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

