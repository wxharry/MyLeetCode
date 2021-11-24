/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
class Solution {
public:

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int int_min = -1000000;
        int int_max = 1000000;
        if (nums1.size() > nums2.size())
        {
            return findMedianSortedArrays(nums2, nums1);
        }
        int m = nums1.size(), n = nums2.size();
        int l=0, r=m, mid, midd;
        while (l <= r)
        {
            mid = l + (r-l)/2;
            midd = (m+n+1)/2-mid;
            double l1 = (mid == 0) ? int_min : nums1[mid-1]; 
            double l2 = (midd == 0) ? int_min : nums2[midd-1]; 
            double r1 = (mid == m) ? int_max : nums1[mid];
            double r2 = (midd == n) ? int_max : nums2[midd];
            if (l1 > r2)
            {
                r = mid;
            }
            else if (l2 > r1)
            {
                l = mid + 1;
            }
            else
            {
                return ((m+n)%2) ? max(l1, l2) : ((max(l1, l2) + min(r1, r2))/2) ;
            }
        }
        return -1 ;
        
    }
};
// @lc code=end

