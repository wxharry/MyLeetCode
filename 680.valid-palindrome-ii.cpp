/*
 * @lc app=leetcode id=680 lang=cpp
 *
 * [680] Valid Palindrome II
 */

// @lc code=start
class Solution
{
public:
    bool validPalindromeIt(string s, int left, int right, int count)
    {
        int l = left, r = right;
        while (l < r)
        {
            if (s[l] != s[r])
            {
                if (count > 0)
                {
                    return false;
                }
                return validPalindromeIt(s, l+1, r, count+1) || validPalindromeIt(s, l, r-1, count+1);
            }
            else
            {
                ++l;
                --r;
            }
        }
        return true;
    }
    bool validPalindrome(string s)
    {
        return validPalindromeIt(s, 0, s.size()-1, 0);
    }
};
// @lc code=end