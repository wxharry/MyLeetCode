/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        int l=1, r=x, mid, sqrt;
        while (l <= r)
        {
            mid = l+(r-l)/2;
            sqrt = x/mid;
            if (sqrt == mid)
            {
                return mid;
            }
            else if(sqrt < mid)
            {
                r=mid-1;
            }
            else if (sqrt > mid)
            {
                l=mid+1;
            }
        }
        return r;
    }
};
// @lc code=end

