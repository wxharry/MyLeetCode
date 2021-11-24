/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */

// @lc code=start
class Solution {
public:
    void dfs(vector<int>& nums, int level, vector<vector<int>>& ans){
        unordered_set <int> visited;
        if (level == nums.size())
        {
            ans.push_back(nums);
        }
        for (size_t i = level; i < nums.size(); ++i)
        {
            if (i != level && visited.find(nums[i]) != visited.end())
            {
                continue;
            }
            visited.insert(nums[i]);
            swap(nums[i], nums[level]);
            dfs(nums, level+1, ans);
            swap(nums[i], nums[level]);
            
        }
        
        
        
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        dfs(nums, 0, ans);
        return ans;
    }
};
// @lc code=end

