/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution {
public:
// brute force
    // vector<int> twoSum(vector<int>& nums, int target) {
    //     for (int i = 0; i < nums.size(); i++)
    //     {
    //         for (int j = i+1; j < nums.size(); j++)
    //         {
    //             if (nums[i]+nums[j]==target)
    //             {
    //                 return vector<int > {i, j};
    //             }
                
    //         }
    //     }
    //     return vector<int> {0, 0};
        
    // }

    // use map to store and find
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> umap;
        for (int i = 0; i < nums.size(); ++i)
        {
            int diff = target-nums[i];
            if(umap.count(diff) > 0) return vector<int>({umap[diff], i});
            umap[nums[i]] = i;
        }
        return vector<int>();
    }

};
// @lc code=end

