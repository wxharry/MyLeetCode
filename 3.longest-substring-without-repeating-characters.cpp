/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.size();
        if (len == 0)
        {
            return 0;
        }
        vector<int> dict(128, -1);
        int maxLen = 0;
        // int start = 0;
        // for (int i = 0; i < len; ++i)
        // {
        //     if(dict[s[i]] >= start){
        //         start = dict[s[i]]+1;
        //     }
        //     dict[s[i]] = i;
        //     maxLen = max(maxLen, i-start+1);
        // }

        // sliding window
        int l=-1, r=0;
        while (r < len)
        {
            if (dict[s[r]] >= l)
            {
                l = dict[s[r]];
            }
            dict[s[r]] = r;
            maxLen = max(maxLen, r-l);
            ++r;
        }
        return maxLen;
    }
};
// @lc code=end

