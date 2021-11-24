/*
 * @lc app=leetcode id=769 lang=cpp
 *
 * [769] Max Chunks To Make Sorted
 */

// @lc code=start
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n=arr.size();
        int mx=arr[0];
        int ans=0;
        for (int i = 0; i < n; ++i)
        {
            mx=max(mx, arr[i]);
            if (mx == i)
            {
                ++ans;
            }
            
        }
        return ans;
    }
};
// @lc code=end

