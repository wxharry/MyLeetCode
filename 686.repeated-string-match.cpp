/*
 * @lc app=leetcode id=686 lang=cpp
 *
 * [686] Repeated String Match
 */

// @lc code=start
class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        if (a=="")
        {
            return -1;
        }
        if (b=="")
        {
            return 0;
        }
        int repeat=1;
        int start=0;
        for (start = 0; start < a.size(); ++start)
        {
            if (a[start] == b[0])
            {
                break;
            }
        }
        if (start == a.size())
        {
            return -1;
        }
        
        for (int i = 0; i < b.size(); i++)
        {
            if (start == a.size())
            {
                ++repeat;
                start = 0;
            }
            if (a[start] != b[i])
            {
                return -1;
            }
            ++start;
        }
        return repeat;
        
    }
};
// @lc code=end

