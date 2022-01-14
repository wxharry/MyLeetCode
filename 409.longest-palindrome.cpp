/*
 * @lc app=leetcode id=409 lang=cpp
 *
 * [409] Longest Palindrome
 */

// @lc code=start
class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> dict(128, 0);
        int ans=0;
        int hasOdd=0;
        for (int i = 0; i < s.size(); ++i)
        {
            ++ dict[s[i]];
            if (dict[s[i]]%2)
            {
                ++hasOdd;
            }
            else{
                --hasOdd;
                ans += 2;
            }
        }
        return hasOdd? ans+1 : ans;
    }
};
// @lc code=end

