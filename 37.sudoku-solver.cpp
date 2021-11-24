/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 */

// @lc code=start
class Solution {
public:
    bool isValid(vector<vector<char> >& board, int x, int y, char target){
        for (int i = 0; i < 9; ++i)
            if(board[i][y] == target)
                return false;
        for (int j = 0; j < 9; ++j)
            if(board[x][j] == target)
                return false;
        int base_x = x/3*3, base_y = y/3*3;
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                if(board[base_x+i][base_y+j] == target) return false;
            }
            
        }
        
        
        return true;
    }
    bool dfs(vector<vector<char> >& board, int i, int j){
        if(i == 9) return true;
        if(j == 9) return dfs(board, i+1, 0);
        if(board[i][j] != '.') return dfs(board, i, j+1);
        for (char k = '1'; k <= '9'; ++k)
        {
            if (isValid(board, i, j, k))
            {
                board[i][j] = k;
                if(dfs(board, i, j+1)) return true;
                board[i][j] = '.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        dfs(board, 0, 0);
    }
};
// @lc code=end

