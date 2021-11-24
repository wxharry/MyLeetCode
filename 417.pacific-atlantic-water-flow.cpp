/*
 * @lc app=leetcode id=417 lang=cpp
 *
 * [417] Pacific Atlantic Water Flow
 */

// @lc code=start
class Solution {
public:
    void dfs(vector<vector<int> >&heights,vector <vector<bool> >& can_reach, int i, int j){
        vector<int> direction {-1, 0, 1, 0, -1};
        if (can_reach[i][j])
        {
            return;
        }
        can_reach[i][j] = true;
        int x, y;
        for (int i = 0; i < 4; ++i)
        {
            x = i + direction[i]; y = j + direction[i+1];
            if (x>=0 && x<heights.size() && y>=0 && y<heights[0].size() && heights[x][y] >= heights[i][j])
            {
                dfs(heights, can_reach, x, y);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int> >& heights) {
        int m, n;
        vector <vector<int>> result;
        m = heights.size();
        n = heights[0].size();
        vector <vector<bool> > can_reach_p(m, vector<bool>(n, false));
        vector <vector<bool> > can_reach_a(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i)
        {
            dfs(heights, can_reach_p, i, 0);
            dfs(heights, can_reach_a, i, n-1);
        }
        for (int j = 0; j < n; ++j)
        {
            dfs(heights, can_reach_p, 0, j);
            dfs(heights, can_reach_a, m-1, j);
        }
        
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (can_reach_a[i][j] && can_reach_p[i][j])
                {
                    result.push_back(vector<int>{i, j});
                }                
            }
            
        }
        return result;
        
    }
};
// @lc code=end

