/*
 * @lc app=leetcode id=130 lang=cpp
 *
 * [130] Surrounded Regions
 */

// @lc code=start
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        queue<pair<int, int>> q;
        int m=board.size(), n=board[0].size();
        vector<vector<char> > ans(m, vector<char> (n, 'X'));
        for (size_t i = 0; i < m; ++i)
        {
            if (board[i][0] == 'O')
                q.push({i, 0});   
            if (board[i][n-1] =='O')
                q.push({i, n-1});   
        }
        for (size_t j = 0; j < n; ++j)
        {
            if (board[0][j] == 'O')
                q.push({0, j});
            if (board[m-1][j] == 'O')
                q.push({m-1, j});
        }
        vector<int> directions{-1, 0, 1, 0, -1};
        while (!q.empty())
        {
            auto[r, c] = q.front();
            q.pop();
            ans[r][c] = 'O';
            int x, y;
            for (size_t i = 0; i < 4; ++i)
            {
                x = r + directions[i]; y = c + directions[i+1];
                if (x >=0 && x < m && y >=0 && y < n && board[x][y] == 'O' && ans[x][y] == 'X')
                {
                    q.push({x, y});
                }
            }
        }
        board = ans;
    }
};
// @lc code=end

