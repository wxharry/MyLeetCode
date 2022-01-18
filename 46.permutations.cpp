/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
class Solution {
public:
    // void dfs(vector <int> nums, int level, vector< vector <int>> &r){
    //     if (level == nums.size())
    //     {
    //         r.push_back(nums);
    //         return;
    //     }
    //     for (int i = level; i < nums.size(); ++i)
    //     {
    //         swap(nums[i], nums[level]);
    //         dfs(nums, level+1, r);
    //         swap(nums[i], nums[level]);
    //     }
    //     return;
        
    // }
    // vector<vector<int>> permute(vector<int>& nums) {
    //     vector< vector <int> > result;
    //     dfs(nums, 0, result); 
    //     return result;
    // }

    // second trial
    vector<vector<int> > re;
    vector<vector<int> > permute(vector<int>& nums) {
        backtracking(nums, 0, vector<int> (), vector<bool> (nums.size(), false));
        return re;
    }

    void backtracking(vector<int>& nums, int level, vector<int> permute, vector<bool> visited){
        if (level == nums.size())
        {
            re.push_back(permute);
            return;
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            if(!visited[i]){
                permute.push_back(nums[i]);
                visited[i] = true;
                backtracking(nums, level+1, permute, visited);
                permute.pop_back();
                visited[i] = false;                
            }
        }
        
    }
};
// @lc code=end

