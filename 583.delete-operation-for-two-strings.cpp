/*
 * @lc app=leetcode id=583 lang=cpp
 *
 * [583] Delete Operation for Two Strings
 */

// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.size(), n=word2.size();
        vector< vector<int> > dp(m+1, vector<int>(n+1, 0));
        for (int i = 0; i < m+1; ++i)
        {
            for (int j = 0; j < n+1; ++j)
            {
                if(i==0){dp[i][j]=j;continue;}
                if(j==0){dp[i][j]=i;continue;}
                if (word1[i-1] == word2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = min(dp[i][j-1], dp[i-1][j]) + 1;
                }
            }
            
        }
        return dp[m][n];
    }
};
// @lc code=end

