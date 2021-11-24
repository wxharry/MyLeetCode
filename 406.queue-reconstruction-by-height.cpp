/*
 * @lc app=leetcode id=406 lang=cpp
 *
 * [406] Queue Reconstruction by Height
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    {
        sort(people.begin(), people.end(), [](vector<int> &x, vector<int> &y)
             { return x[1] < y[1]; });
        vector<vector<int>> r;
        int count = 0;
        int n;
        r.push_back(people[0]);
        for (int i = 1; i < people.size(); ++i)
        {
            count = 0;
            n = r.size();
            int j;
            for (j = 0; j < n; ++j)
            {
                if (people[i][0] <= r[j][0])
                {
                    ++count;
                }
                if (count > people[i][1])
                {
                    r.insert(r.begin()+j, people[i]);
                    break;
                }
                
            }
            if (j == n)
            {
                r.push_back(people[i]);
            }
        }
        return r;
    }
};
// @lc code=end
