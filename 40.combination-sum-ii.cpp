/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */

// @lc code=start
class Solution {
public:
    void dfs(vector<int>& candidates, vector<vector<int>>& ans, vector<int> comb, int level, int target){
        if (target == 0)
        {
            ans.push_back(comb);
            return;
        }
        for (size_t i = level; i < candidates.size(); ++i)
        {
            if(candidates[i] > target) return ;
            if(i>0 && candidates[i] == candidates[i-1] && i != level) continue;
            comb.push_back(candidates[i]);
            dfs(candidates, ans, comb, i+1, target - candidates[i]);
            comb.pop_back();
        }
        
                   
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> comb;
        dfs(candidates, ans, comb, 0, target);
        return ans;
    }
};
// @lc code=end

