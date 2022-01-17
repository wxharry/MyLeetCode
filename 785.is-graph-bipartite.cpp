/*
 * @lc app=leetcode id=785 lang=cpp
 *
 * [785] Is Graph Bipartite?
 */

// @lc code=start
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> nodes(graph.size(), 0);
        deque<int> dq;
        for (int i = 0; i < graph.size(); ++i)
        {
            if(nodes[i]) continue;
            ++nodes[i];
            dq.push_back(i);
            while (!dq.empty())
            {
                int v = dq.front();
                dq.pop_front();
                for (int j = 0; j < graph[v].size(); ++j)
                {
                    int u = graph[v][j];
                    if (nodes[u] == nodes[v])
                    {
                        return false;
                    }
                    if(nodes[u] == 0){
                        nodes[u] = -nodes[v];
                        dq.push_back(u);
                    }
                }
            }
        }
        return true;
    }
};
// @lc code=end

