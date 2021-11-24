/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mmap;
        int max_count = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            max_count = max(max_count, ++ mmap[nums[i]]);
        }
        vector< vector < int > >bucket(max_count+1);
        for (auto &&i : mmap)
        {
            bucket[i.second].push_back(i.first);
        }
        vector<int> result;
        for (int i = max_count; i >=0 && k > 0 ; --i)
        {
            vector <int> t = bucket[i];
            for (int j = 0; j < t.size(); ++j)
            {
                result.push_back(t[j]);
                --k;
                if (k == 0)
                {
                    return result;
                }
                
            }
           
        }
        return result;
    }
};
// @lc code=end

