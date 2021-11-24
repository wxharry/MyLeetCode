/*
 * @lc app=leetcode id=934 lang=cpp
 *
 * [934] Shortest Bridge
 */

// @lc code=start
class Solution {
public:
    void dfs(vector<vector<int>>& grid, deque<pair<int, int> >& points, int i, int j){
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 2)
        {
            return;
        }
        if (grid[i][j] == 0)
        {
            points.push_back({i, j});
            return;
        }
        grid[i][j] = 2;
        dfs(grid, points, i-1, j);
        dfs(grid, points, i, j-1);
        dfs(grid, points, i+1, j);
        dfs(grid, points, i, j+1);
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        deque<pair<int, int> > points;
        bool flipped = false;
        for (int i = 0; i < m; ++i)
        {
            if(flipped) break;
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 1)
                {
                    dfs(grid, points, i, j);
                    flipped=true;
                    break;
                }
                

            }
        }
        int x, y;
        int level = 0;
        vector<int> directions{-1, 0, 1, 0, -1};
        while (!points.empty())
        {
            ++level;
            int n_points = points.size();
            while (n_points--)
            {
                auto [r, c] = points.front();
                points.pop_front();
                for (int i = 0; i < 4; ++i)
                {
                    x = r + directions[i]; y = c + directions[i+1];
                    if (x>=0 && x < m && y >=0 && y < n)
                    {
                        if (grid[x][y] == 2)
                        {
                            continue;
                        }
                        if (grid[x][y] == 1)
                        {
                            return level;
                        }
                        points.push_back({x, y});
                        grid[x][y] = 2;
                        
                    }
                    
                }
                
            }
            
        }
        return 0;
        
    }
};
// @lc code=end

