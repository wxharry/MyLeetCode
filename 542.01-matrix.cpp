/*
 * @lc app=leetcode id=542 lang=cpp
 *
 * [542] 01 Matrix
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        return updateMatrix2_dp(mat);
    }

    vector<vector<int>> updateMatrix1(vector<vector<int>>& mat) {
        int m=mat.size(), n=mat[0].size();
        vector< vector <int>> dp(m, vector<int>(n, INT_MAX-1));
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (mat[i][j] == 0)
                {
                    dp[i][j] = 0;
                }
                else
                {
                    if (i > 0)
                    {
                        dp[i][j] = min(dp[i][j], dp[i-1][j] + 1);
                    }
                    if (j > 0)
                    {
                        dp[i][j] = min(dp[i][j], dp[i][j-1] + 1);
                    }                    
                }
            }
        }
        for (int i = m-1; i >=0; --i)
        {
            for (int j = n-1; j >=0; --j)
            {
                if (mat[i][j] != 0)
                {
                    if (i < m-1)
                    {
                        dp[i][j] = min(dp[i][j], dp[i+1][j] + 1);
                    }
                    if (j < n-1)
                    {
                        dp[i][j] = min(dp[i][j], dp[i][j+1] + 1);
                    }                    
                }
            }
        }
        return dp;
    }

    // second trial: bfs - expand visited space to update ans;
    vector<vector<int> > updateMatrix2_bfs(vector<vector<int> >& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<bool> > visited (m, vector<bool>(n, false));
        vector<vector<int> > ans(m, vector<int>(n, 0));
        queue<pair<int, int> > q;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if(mat[i][j] == 0){
                    q.push({i, j});
                    visited[i][j] = true;
                }
            }
        }
        int step=0;
        vector<int> directions = {-1, 0, 1, 0, -1};
        while (!q.empty())
        {
            int count = q.size();
            for (int i = 0; i < count; ++i){
                auto pt = q.front();
                q.pop();
                ans[pt.first][pt.second] = step;
                for (int k = 0; k < 4; ++k)
                {
                    int x = pt.first + directions[k];
                    int y = pt.second + directions[k+1];
                    if(x >= 0 && x < m && y >=0 && y < n && !visited[x][y]){
                        visited[x][y] = true;
                        q.push(pair<int, int>({x, y}));
                    }
                }                
            }
            ++ step;
        }
        return ans;        
    }

    // second trial - dp: update each answer twice
                    // 1. scan from top-left to down-right and update values based on the values at the up and left 
                    // 2. scan from down-right to top-left and update values based on the values at the down and right
    vector<vector<int> > updateMatrix2_dp(vector<vector<int> >& mat) {
        int m = mat.size(),
            n = mat[0].size();
        vector<vector<int> > ans(m, vector<int>(n, m+n));
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                if(mat[i][j]){
                    if(i > 0) ans[i][j] = min(ans[i-1][j] + 1, ans[i][j]);
                    if(j > 0) ans[i][j] = min(ans[i][j-1] + 1, ans[i][j]);
                }
                else{
                    ans[i][j] = 0;
                }
            }
        }
        for (int i = m - 1; i >= 0; --i)
        {
            for (int j = n - 1; j >= 0; --j)
            {
                if(mat[i][j]){
                    if(i < m - 1) ans[i][j] = min(ans[i+1][j] + 1, ans[i][j]);
                    if(j < n - 1) ans[i][j] = min(ans[i][j+1] + 1, ans[i][j]);
                }
            }
        }
        return ans;        
    }
};
// @lc code=end

