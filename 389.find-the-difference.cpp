/*
 * @lc app=leetcode id=389 lang=cpp
 *
 * [389] Find the Difference
 */

// @lc code=start
class Solution {
public:
    char findTheDifference(string s, string t) {
        if (!s.size())
        {
            return t[0];
        }
        vector<int> v(256, 0);
        for (int i = 0; i < t.size(); i++)
        {
            ++v[t[i]];
        }
        for (int i = 0; i < s.size(); i++)
        {
            --v[s[i]];
        }
        int i=0;
        for (; i < v.size(); i++)
        {
            if (v[i])
            {
                break;
            }
        }
        return i;
    }
};
// @lc code=end

