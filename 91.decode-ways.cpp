/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 */

// @lc code=start
class Solution {
public:
    int numDecodings(string s) {
        int n= s.size();
        if (s[0] == '0')
        {
            return 0;
        }
        
        if(n < 2) return n;
        
        
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        int prev = s[0] - '0';

        for (int i = 2; i <= n; ++i)
        {
            int cur = s[i-1] - '0';
            if (cur == 0 && (prev == 0 || prev >2))
            {
                return 0;
            }
            if (prev == 1 || prev == 2 && cur < 7 && cur >= 0)
            {
                if (cur != 0)
                {
                    dp[i] = dp[i-1] + dp[i-2];
                }
                else
                {
                    dp[i] = dp[i-2];
                }
                
                
            }
            else
            {
                dp[i] = dp[i-1];
            }
            prev = cur;
            
        }
        return dp[n];
    }
};
// @lc code=end

