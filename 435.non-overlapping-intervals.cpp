/*
 * @lc app=leetcode id=435 lang=cpp
 *
 * [435] Non-overlapping Intervals
 */

// @lc code=start
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int> >& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>&a, vector<int> &b){
                return a[1] < b[1];
        });
        int pre_end = intervals[0][1];
        int count = 0;
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] < pre_end)
            {
                ++ count;
            }
            else
            {
                pre_end = intervals[i][1];
            }
        }
        return count;
    }
};
// @lc code=end

