/*
 * @lc app=leetcode id=303 lang=cpp
 *
 * [303] Range Sum Query - Immutable
 */

// @lc code=start
class NumArray {
    vector<int> sums;
public:
    NumArray(vector<int>& nums) {
        int sum=0;
        sums.push_back(0);
        for (int i = 0; i < nums.size(); ++i)
        {
            sum += nums[i];
            sums.push_back(sum);
        }
    }
    
    int sumRange(int left, int right) {
        return sums[right+1] - sums[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end

