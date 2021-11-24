/*
 * @lc app=leetcode id=462 lang=cpp
 *
 * [462] Minimum Moves to Equal Array Elements II
 */

// @lc code=start
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        int res=0;
        for (int i = 0; i < n/2; ++i)
        {
            res+= nums[n-1-i] - nums[i];
        }
        
        return res;
    }
};
// @lc code=end

