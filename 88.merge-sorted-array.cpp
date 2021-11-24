/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 */

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-- + n-- -1;
        while (m >= 0 && n >= 0)
        {
            nums1[i] = nums1[m] > nums2[n] ? nums1[m--] : nums2[n--];
            --i;
        }
        while (n >= 0)
        {
            nums1[i--] = nums2[n--];
        }
        
                
    }
};
// @lc code=end

