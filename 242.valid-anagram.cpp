/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size()!=t.size())
        {
            return false;
        }
        
        vector<int>v(256, 0);
        for (int i = 0; i < s.size(); ++i)
        {
            ++v[s[i]];
            --v[t[i]];
        }
        for (auto &i : v)
        {
            if (i != 0)
            {
                return false;
            }
            
        }
        return true;
    }
};
// @lc code=end

