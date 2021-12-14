/*
 * @lc app=leetcode id=773 lang=cpp
 *
 * [773] Sliding Puzzle
 */

// @lc code=start
class Solution {
public:
    int slidingPuzzle(vector<vector<int> >& board) {
        string boardStr = "";
        string target = "123450";
        int m=board.size();
        int n=board[0].size();
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                boardStr += to_string(board[i][j]);
            }
        }
        deque<pair<string, int> > q;
        q.push_back({boardStr, 0});
        unordered_set<string> visited;
        visited.insert(boardStr);
        vector<int> direction({-1, 0, 1, 0, -1});
        while (!q.empty())
        {
            auto s = q.front();
            q.pop_front();
            if (s.first == target)
            {
                return s.second;
            }
            auto ss = s.first;
            // cout << ss << endl;
            int idx = ss.find('0');
            for (int k = 0; k < 4; k++)
            {
                int i=idx/n, j=idx%n;
                int x=i+direction[k], y=j+direction[k+1];
                if (x < 0 || x >= m || y < 0 || y >= n)
                {
                    continue;
                }
                int idx_new = idx+direction[k]*n+direction[k+1];
                string temp = ss;
                swap(temp[idx_new], temp[idx]);
                if (!visited.count(temp))
                {
                    visited.insert(temp);
                    q.push_back({temp, s.second+1});
                }
                
            }
        }
        return -1;
    }
};
// @lc code=end

