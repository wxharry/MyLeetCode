/*
 * @lc app=leetcode id=384 lang=cpp
 *
 * [384] Shuffle an Array
 */

// @lc code=start
class Solution {
public:
    vector<int> origin;
    Solution(vector<int>& nums) {
        origin = nums;
    }
    
    vector<int> reset() {
        return origin;
    }
    
    vector<int> shuffle() {
        vector<int> temp = origin;
        for (int i = origin.size()-1; i >=0 ; --i)
        {
            swap(temp[i], temp[rand()%(i+1)]);
        }
        return temp;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
// @lc code=end

