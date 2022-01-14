/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 */

// @lc code=start
class Solution {
public:
    void calcNext(string needle, vector<int>& next){
        for (int i = 1, p = -1; i < needle.size(); ++i)
        {
            while (p > -1 && needle[p+1] != needle[i])
            {
                p = next[p];
            }
            if (needle[p+1] == needle[i])
            {
                ++p;
            }
            next[i] = p;
        }
    }
    int strStr(string haystack, string needle) {
        int len = needle.size();
        if (len == 0)
        {
            return 0;
        }
        vector<int> next(len, -1);
        calcNext(needle, next);
        for (int i = 0, p = -1; i < haystack.size(); ++i)
        {
            while (p > -1 && haystack[i] != needle[p+1])
            {
                p = next[p];
            }
            if (haystack[i] == needle[p+1])
            {
                ++p;
            }
            if (p == needle.size()-1)
            {
                return i - p;
            }
        }
        return -1;
    }
};
// @lc code=end

