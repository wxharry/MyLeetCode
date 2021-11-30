/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>&b){return a[0] < b[0];});
        vector<vector<int> > ans;
        for (auto &v : intervals)
        {
            cout << v[0] << "," << v[1] << endl;
        }
        ans.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] <= ans[ans.size()-1][1])
            {
                ans[ans.size()-1][1] = max(intervals[i][1], ans[ans.size()-1][1]);
            }
            else
            {
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};
// @lc code=end

