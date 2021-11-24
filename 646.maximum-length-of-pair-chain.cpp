/*
 * @lc app=leetcode id=646 lang=cpp
 *
 * [646] Maximum Length of Pair Chain
 */

// @lc code=start
class Solution
{
public:
    int findLongestChain(vector<vector<int>> &pairs)
    {
        sort(pairs.begin(), pairs.end(), [](vector<int> &a, vector<int> &b)
             { return a[1] < b[1] || a[1] == b[1] && a[0] < b[0]; });
        int n = pairs.size();
        int maxLen = 1;
        if (n == 1)
            return 1;
        vector<int> dp(n + 1, 1);
        dp[0] = 0;
        for (int i = 2; i < n + 1; ++i)
        {
            for (int j = i-1; j > 0; --j)
            {
                if (pairs[i - 1][0] > pairs[j-1][1])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                    maxLen = max(dp[i], maxLen);
                }
            }
        }
        return maxLen;
    }
};
// @lc code=end
