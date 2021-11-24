/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> chars (128, 0);
        vector<int> flag (128, false);
        for (int i = 0; i < t.size(); ++i)
        {
            ++ chars[t[i]];
            flag[t[i]] = true;
        }
        int count=0, l=0, min_l=0, min_size=s.size()+1;
        for (int r = 0; r < s.size(); ++r)
        {
            if (flag[s[r]])
            {
                if (--chars[s[r]] >= 0)
                {
                    ++ count;
                }
                while (count == t.size())
                {
                    if (r-l+1 < min_size)
                    {
                        min_size = r-l+1;
                        min_l = l;
                    }
                    if (flag[s[l]]&&++chars[s[l]]>0)
                    {
                        --count;
                    }
                    ++l;
                }
            }
        }
        return min_size > s.size() ? "": s.substr(min_l, min_size);
    }
};
// @lc code=end

