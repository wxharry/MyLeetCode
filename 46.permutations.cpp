/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
class Solution {
public:
    void dfs(vector <int> nums, int level, vector< vector <int>> &r){
        if (level == nums.size())
        {
            r.push_back(nums);
            return;
        }
        for (int i = level; i < nums.size(); ++i)
        {
            swap(nums[i], nums[level]);
            dfs(nums, level+1, r);
            swap(nums[i], nums[level]);
        }
        return;
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector< vector <int> > result;
        dfs(nums, 0, result); 
        return result;
    }
};
// @lc code=end

