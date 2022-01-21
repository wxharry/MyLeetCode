/*
 * @lc app=leetcode id=740 lang=cpp
 *
 * [740] Delete and Earn
 */

// @lc code=start
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int, int> umap;
        int maximum = nums[0];
        for (auto &num : nums)
        {
            if(umap.count(num)) ++ umap[num];
            else umap[num] = 1;
            maximum = max(maximum, num);
        }
        int skip=0;
        int earn=0;
        for (int i = 1; i < maximum+1; ++i)
        {
            int last_earn = earn;
            if(umap.count(i)){
                earn = skip + i*umap[i];
            }
            skip = max(skip, last_earn);
        }
        return max(skip, earn);
    }
};
// @lc code=end

