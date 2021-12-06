/*
 * @lc app=leetcode id=205 lang=cpp
 *
 * [205] Isomorphic Strings
 */

// @lc code=start
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> v(256, 0);
        vector<int> w(256, 0);
        for (int i = 0; i < s.size(); ++i)
        {
            if (!v[s[i]]&&!w[t[i]])
            {
                v[s[i]] = t[i];
                w[t[i]] = s[i];
            }
            else if(v[s[i]] != t[i]||w[t[i]]!=s[i])
            {
                return false;
            }
        }
        return true;        
    }
};
// @lc code=end

