/*
 * @lc app=leetcode id=818 lang=cpp
 *
 * [818] Race Car
 */

// @lc code=start
class Solution {
public:
    int racecar(int target) {
        queue<pair<int, int> > q({{0, 1}});
        unordered_map<int, unordered_map<int, bool>> visited;
        int step=0;
        while (!q.empty())
        {
            int count = q.size();
            for (int i = 0; i < count; ++i)
            {
                auto [pos, speed] = q.front();
                q.pop();
                if(pos == target) return step;
                int new_pos, new_speed;
                if (abs(pos + speed - target) < target)
                {
                    // not far away, keep accelerating
                    new_pos = pos+speed; new_speed = speed*2;
                    if (!visited[new_pos][new_speed])
                    {
                        visited[new_pos][new_speed] = true;
                        q.push({new_pos, new_speed});
                    }
                }
                // reverse
                new_pos = pos; new_speed = speed < 0 ? 1 : -1;
                if (!visited[new_pos][new_speed])
                {
                    visited[new_pos][new_speed] = true;
                    q.push({new_pos, new_speed});
                }
            }
            ++step;
        }
        return step;
    }
};
// @lc code=end

