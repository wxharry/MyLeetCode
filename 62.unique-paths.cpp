/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */

// @lc code=start
class Solution {
public:
    int uniquePaths(int m, int n) {
        return uniquePaths_1d(m, n);
    }

    int uniquePaths_2d(int m, int n) {
        vector<vector<int> > dp(m, vector<int>(n, 0));
        dp[0][0] = 1;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if(i == 0 && j == 0) continue;
                if(i == 0){
                    dp[i][j] = dp[i][j-1];
                } 
                else if(j == 0){
                  dp[i][j] = dp[i-1][j];  
                } 
                else{
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
    }
    // better runtime and memory usage
    int uniquePaths_1d(int m, int n) {
        vector<int> dp(n, 0);
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                if(i == 0){
                    dp[j] = 1;
                }
                else{
                    if(j == 0) dp[j];
                    else{
                        dp[j] += dp[j-1];
                    }
                }
            }
        }
        return dp[n-1];        
    }
};
// @lc code=end

