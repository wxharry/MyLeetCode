/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 */

// @lc code=start
class Solution {
public:
    void backtracking(vector<vector<int> >&result, int n, int k, int start, int level, vector<int> nums){
        if (k == level)
        {
            result.push_back(nums);
            return;
        }
        for (int i = start; i <= n; ++i)
        {
            nums[level] = i;
            backtracking(result, n, k, i+1, level+1, nums);
        }
        
        
    }
    vector<vector<int>> combine(int n, int k) {
        vector < vector<int>> result;
        vector<int> nums(k);
        backtracking(result, n, k, 1, 0, nums);
        return result;
    }
};
// @lc code=end

