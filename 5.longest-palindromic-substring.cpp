/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        int start, end;
        int length = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            int l=i, r=i;
            while (l >= 0 && r < s.size() && s[l] == s[r]){
                --l;
                ++r;
            }
            if (r - l - 1 > length){
                length = r - l - 1;
                start = l+1;
                end = r;                        
            }
            l = i, r = i + 1;            
            while (l >= 0 && r < s.size() && s[l] == s[r]){
                --l;
                ++r;
            }
            if (r - l - 1 > length){
                length = r - l - 1;
                start = l+1;
                end = r;                        
            }
        }
        return s.substr(start, length);
    }
};
// @lc code=end

