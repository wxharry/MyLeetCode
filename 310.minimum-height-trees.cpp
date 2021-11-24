/*
 * @lc app=leetcode id=310 lang=cpp
 *
 * [310] Minimum Height Trees
 */

// @lc code=start
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1)
        {
            return vector<int>({0});
        }
        
        unordered_map<int, vector<int> > connection;
        deque<int>q;
        vector<int> res;
        for (size_t i = 0; i < edges.size(); ++i)
        {
            auto v = edges[i];
            connection[v[0]].push_back(v[1]);
            connection[v[1]].push_back(v[0]);
        }
        for (auto &[k, v] : connection)
        {
            if (v.size()==1)
            {
                q.push_back(k);
            }
        }
        while (!q.empty())
        {
            res = vector<int>(q.begin(), q.end());
            int n = q.size();
            for (size_t i = 0; i < n; ++i)
            {
                auto node = q.front();
                q.pop_front();
                vector<int> temp;
                auto neighbour = connection[node][0];
                for (auto &&foo : connection[neighbour])
                {
                    if(foo != node) temp.push_back(foo);
                }
                connection[neighbour] = temp;
                if (temp.size() == 1)
                {
                    q.push_back(neighbour);
                }
            }
        }
        return res;
    }
};
// @lc code=end

