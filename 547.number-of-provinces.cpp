/*
 * @lc app=leetcode id=547 lang=cpp
 *
 * [547] Number of Provinces
 */

// @lc code=start
class Solution {
public:
    void dfs(vector<vector<int> >&isConnected, int k, vector<bool>& visited){
        visited[k] = true;
        for (int i = 0; i < isConnected.size(); ++i)
        {
            if (i != k && isConnected[k][i] && !visited[i])
            {
                dfs(isConnected, i, visited);
            }
        }
        
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        if (isConnected.empty())
        {
            return 0;
        }
        
        vector<bool> visited(isConnected.size(), false);
        int count = 0;
        for (int i = 0; i < visited.size(); ++i)
        {
            if (!visited[i])
            {
                dfs(isConnected, i, visited);
                ++ count;
            }
            
        }
        return count;
        
    }
};
// @lc code=end

