/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start
class Solution {
public:

    // void dfs(vector<vector<char> >& board, vector<vector<bool> >& visited, string word, int level, int i, int j, bool& find){
    //     if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[level] || visited[i][j] || find)
    //     {
    //         return;
    //     }
    //     if (level == word.size()-1)
    //     {
    //         find = true;
    //         return;
    //     }
    //     vector<int> direction{-1, 0, 1, 0, -1};
    //     visited[i][j] = true;
    //     for (int k = 0; k < 4; ++k)
    //     {
    //         int x = i + direction[k]; int y = j + direction[k+1];
    //         dfs(board, visited, word, level+1, x, y, find);
    //     }
    //     visited[i][j] = false;
    // }

    // bool exist(vector<vector<char> >& board, string word) {
    //     int m = board.size(), n= board[0].size();
    //     bool find=false;
    //     vector<vector<bool> > visited(m, vector<bool>(n, false));
    //     for (int i = 0; i < m; ++i)
    //     {
    //         for (int j = 0; j < n; ++j)
    //         {
    //             dfs(board, visited, word, 0, i, j, find);
    //             if (find)
    //             {
    //                 return true;
    //             }
                
    //         }
            
    //     }
        
    //      return false;
    // }

    // second trial
    vector<int> directions = {-1, 0, 1, 0, -1};
    bool exist(vector<vector<char> >& board, string word) {
        int m = board.size(),
            n = board[0].size();
        bool found=false;
        vector<vector<bool> > visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                dfs(board, word, i, j, 0, visited, found);
                if(found) return true;
            }
        }
        return false;
    }
    void dfs(vector<vector<char> >& board, string word, int i, int j, int level, vector<vector<bool> >& visited, bool& found){
        if(found || board[i][j] != word[level]) return;
        if(level == word.size()-1){
            found = word[level] == board[i][j];
            return;
        }
        for (int k = 0; k < 4; ++k)
        {
            int x = i + directions[k], y = j + directions[k+1];
            if (x >= 0 && x < board.size() && y >= 0 && y < board[0].size() && !visited[x][y])
            {
                visited[i][j] = true;
                dfs(board, word, x, y, level+1, visited, found);
                visited[i][j] = false;
            }
        }
    }
};
// @lc code=end

