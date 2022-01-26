/*
 * @lc app=leetcode id=1105 lang=cpp
 *
 * [1105] Filling Bookcase Shelves
 */

// @lc code=start
class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<int> dp(n, INT_MAX);
        for (int i = 0; i < n; ++i)
        {
            int h=0, w=0;
            for (int j = i; j >= 0; --j)
            {
                w += books[j][0];
                if(w > shelfWidth) break;
                h = max(h, books[j][1]);
                dp[i] = min(dp[i], (j == 0 ? 0 : dp[j-1]) + h);
            }
        }
        return dp[n-1];        
    }
};
// @lc code=end

