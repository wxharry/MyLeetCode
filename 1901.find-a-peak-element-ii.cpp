/*
 * @lc app=leetcode id=1901 lang=cpp
 *
 * [1901] Find a Peak Element II
 */

// @lc code=start
class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int startCol=0, endCol=mat[0].size()-1;
        while (startCol <= endCol)
        {
            int maxRow=0, midCol=startCol + (endCol-startCol)/2;
            for (int row = 0; row < mat.size(); ++row)
            {
                maxRow = mat[maxRow][midCol] < mat[row][midCol]?row:maxRow;
            }
            if ((midCol+1 > endCol || mat[maxRow][midCol]>mat[maxRow][midCol+1])&&(midCol-1 < startCol || mat[maxRow][midCol]>mat[maxRow][midCol-1]))
            {
                return vector<int>{maxRow, midCol};
            }
            else if (midCol+1 <= endCol && mat[maxRow][midCol]<mat[maxRow][midCol+1])
            {
                startCol=midCol+1;
            }
            else
            {
                endCol=midCol-1;
            }
        }
        return vector<int>{-1, -1};
    }
};
// @lc code=end

