/*
 * @lc app=leetcode id=452 lang=cpp
 *
 * [452] Minimum Number of Arrows to Burst Balloons
 */

// @lc code=start
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size() == 1)
        {
            return 1;
        }
        sort(points.begin(),points.end(), [](vector<int> &x, vector<int> &y){
            return x[1] < y[1];
        });
        int count = 1;
        int prev = points[0][1];
        for (int i = 1; i < points.size(); i++)
        {
            if (prev < points[i][0])
            {
                prev = points[i][1];
                ++ count;
            }
            
        }
        return count;
    }
};
// @lc code=end

