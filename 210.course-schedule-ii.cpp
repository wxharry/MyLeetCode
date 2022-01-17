/*
 * @lc app=leetcode id=210 lang=cpp
 *
 * [210] Course Schedule II
 */

// @lc code=start
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> degree(numCourses, 0), ans;
        vector<vector<bool> > graph (numCourses, vector<bool> (numCourses, false));
        for (auto &p : prerequisites)
        {
            graph[p[1]][p[0]] = true;
            ++degree[p[0]];
        }
        // int num=0;
        // int isLoop=true;
        deque<int> dq;
        for (int i = 0; i < numCourses; ++i)
        {
            if (degree[i] == 0)
            {
                dq.push_back(i);
            }
            
        }
        while (!dq.empty())
        {
            int v = dq.front();
            dq.pop_front();
            ans.push_back(v);
            for (int i = 0; i < numCourses; ++i)
            {
                if (graph[v][i])
                {
                    graph[v][i] = false;
                    -- degree[i];
                    if (degree[i] == 0)
                    {
                        dq.push_back(i);
                    }
                }
            }
        }
        for (int i = 0; i < numCourses; ++i)
        {
            if (degree[i])
            {
                return vector<int> ();
            }
        }
        return ans;
    }
};
// @lc code=end

