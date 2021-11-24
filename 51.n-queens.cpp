/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 */

// @lc code=start
class Solution {
public:
    void dfs(vector<vector<string>>& result, vector <string>& board, vector <bool> column,vector <bool> ldiag, vector <bool> rdiag, int level, int n){
        if (level == n)
        {
            result.push_back(board);
            return;
        }
        for (int i = 0; i < n; ++i)
        {
            if (column[i] || ldiag[n-level+i-1]||rdiag[level+i])
            {
                continue;
            }
            board[level][i] = 'Q';
            column[i] = ldiag[n-level+i-1] = rdiag[level+i] = true;
            dfs(result, board, column, ldiag, rdiag, level+1, n);
            board[level][i] = '.';
            column[i] = ldiag[n-level+i-1] = rdiag[level+i] = false;
            
        }
        
        
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        if (n==0)
        {
            return result;
        }
        vector <string> board(n, string(n, '.'));
        vector <bool> column(n, false), ldiag(2*n-1, false), rdiag(2*n-1, false);
        dfs(result, board, column, ldiag, rdiag, 0, n);
        return result;
            
    }
};
// @lc code=end

