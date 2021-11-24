/*
 * @lc app=leetcode id=695 lang=cpp
 *
 * [695] Max Area of Island
 */

// @lc code=start
class Solution {
public:
    int AreaOfIsland(vector < vector <int> > & grid, int i, int j){
        if (i>=0 && i < grid.size() && j >=0 && j < grid[i].size()&&grid[i][j] == 1)
        {
            grid[i][j] = 0;
            return 1 + AreaOfIsland(grid, i-1, j) + AreaOfIsland(grid, i+1, j) + AreaOfIsland(grid, i, j-1) + AreaOfIsland(grid, i, j+1);
        }
        return 0;
        
    }
    int maxAreaOfIsland(vector<vector<int> > & grid) {
        int maxArea = 0;
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (grid[i][j] == 1)
                    maxArea = max(maxArea, AreaOfIsland(grid, i, j));
            }
            
        }
        return maxArea;
        
    }
};
// @lc code=end

