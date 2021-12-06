/*
 * @lc app=leetcode id=647 lang=cpp
 *
 * [647] Palindromic Substrings
 */

// @lc code=start
class Solution {
public:
    int countSubstrings(string s) {
        int cnt=0;
        for (int i = 0; i < s.size(); ++i)
        {
            int l=i, r=i;
            while (l >=0 && r <s.size() && s[l] == s[r])
            {
                ++cnt;
                --l;++r;
            }
            l=i, r=i+1;
            while (l >=0 && r<s.size() && s[l] == s[r])
            {
                ++cnt;
                --l;++r;
            }
            
        }
        return cnt;
    }
};
// @lc code=end

