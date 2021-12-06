/*
 * @lc app=leetcode id=696 lang=cpp
 *
 * [696] Count Binary Substrings
 */

// @lc code=start
class Solution {
public:
    int countBinarySubstrings(string s) {
        int cnt=0;
        int ans=0;
        int dp=1;
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] == s[i-1])
            {
                ++dp;
            }
            else
            {
                cnt=dp;
                dp=1;
            }
            if (cnt >= dp)
            {
                ++ans;
            }
        }
        return ans;
    }
};
// @lc code=end

