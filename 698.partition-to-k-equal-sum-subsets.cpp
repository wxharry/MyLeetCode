/*
 * @lc app=leetcode id=698 lang=cpp
 *
 * [698] Partition to K Equal Sum Subsets
 */

// @lc code=start
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(nums.size() < k || sum % k) return false;
        vector<bool> visited(n, false);
        return backtrack(nums, k, visited, 0, 0, sum / k);

    }

    bool backtrack(vector<int>& nums, int k, vector<bool>&visited, int j, int current_sum, int target){
        if (k == 1)
        {
            return true;
        }
        if (current_sum == target)
        {

            return backtrack(nums, k-1, visited, 0, 0, target);
        }
        
        for (int i = j; i < nums.size(); ++i)
        {
            if (!visited[i] && current_sum + nums[i] <= target)
            {
                visited[i] = true;
                if(backtrack(nums, k, visited, i, current_sum + nums[i], target))
                    return true;
                visited[i] = false;
            }
        }
        return false;
    }
};
// @lc code=end

