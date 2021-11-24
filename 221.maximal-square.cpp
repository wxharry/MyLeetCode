/*
 * @lc app=leetcode id=221 lang=cpp
 *
 * [221] Maximal Square
 */

// @lc code=start
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m+1, vector<int> (n+1, 0));
        int max_side = 0;
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (matrix[i-1][j-1] == '1')
                {
                    dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
                }
                max_side = max(max_side, dp[i][j]);
            }
        }
        return max_side* max_side;
    }
};
// @lc code=end

