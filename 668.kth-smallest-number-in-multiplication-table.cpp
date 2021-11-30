/*
 * @lc app=leetcode id=668 lang=cpp
 *
 * [668] Kth Smallest Number in Multiplication Table
 */

// @lc code=start
class Solution {
public:
    int helper(int m, int n, int mid){
        int c=0;
        for (int i = 1; i <= m; ++i)
        {
            c += min(n, mid/i);
        }
        return c;
    }
    int findKthNumber(int m, int n, int k) {
        int l=0, r=m*n;
        while (l <= r)
        {
            int mid = l + (r-l)/2;
            if (helper(m, n, mid) < k)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
            
        }
        return l;
    }
};
// @lc code=end

