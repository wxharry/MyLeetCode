/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 */

// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.size(), n=b.size();
        if(m > n) return addBinary(b, a);
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int addbit=0;
        string res;
        for (int i = 0; i < m; ++i)
        {
            int foo = a[i]-'0' + b[i]-'0' + addbit;
            addbit = foo/2;
            res+=to_string(foo%2);
        }
        for (int i = m; i < n; ++i)
        {
            int foo = b[i]-'0' + addbit;
            addbit = foo/2;
            res+=to_string(foo%2);
        }
        if (addbit)
        {
            res+=to_string(addbit);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

