/*
 * @lc app=leetcode id=240 lang=cpp
 *
 * [240] Search a 2D Matrix II
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n=matrix[0].size();
        int i=0, j=n-1;
        while (i < m && j >= 0)
        {
            if (matrix[i][j] > target)
            {
                --j;
            }
            else if (matrix[i][j] < target)
            {
                ++i;
            }
            else
            {
                return true;
            }
            
        }
        return false;
        
    }
};
// @lc code=end

