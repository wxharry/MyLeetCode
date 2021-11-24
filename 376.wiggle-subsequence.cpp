/*
 * @lc app=leetcode id=376 lang=cpp
 *
 * [376] Wiggle Subsequence
 */

// @lc code=start
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        // if(n==1) return 1;
        // if(n==2) return (nums[0] != nums[1] )+ 1;
        // vector<int> dp(n+1, 1);
        // dp[0]=0; dp[1]=1; dp[2]=2;
        // for (int i = 3; i < n+1; ++i)
        // {
        //     if((nums[i-1] - nums[i-2])*(nums[i-2] - nums[i-3]) < 0){
        //         dp[i] = dp[i-1]+1;
        //     }
        //     else
        //     {
        //         for (int j = i-1; j >=2; --j)
        //         {
        //             if ((nums[i-1] - nums[j-1])*(nums[j-1] - nums[j-2]) < 0)
        //             {
        //                 dp[i] = dp[j] + 1;
        //                 break;
        //             }
        //             if (j==2)
        //             {
        //                 if(nums[i-1] != nums[0])
        //                     dp[i] = 2;
        //                 else
        //                     dp[i] = 1;
        //             }
        //         }
                
        //     }
            
        // }
        // return dp[n];
        vector<int> up(n), down(n);
        up[0] = down[0] = 1;
        for (int i = 1; i < n; ++i)
        {
            if (nums[i]>nums[i-1])
            {
                up[i] = down[i-1]+1;
                down[i] = down[i-1];
            }
            else if (nums[i]<nums[i-1])
            {
                down[i] = up[i-1]+1;
                up[i] = up[i-1];
            }
            else
            {
                up[i] = up[i-1];
                down[i] = down[i-1];
            }
            
            
        }
        return max(up[n-1], down[n-1]);
    }
};
// @lc code=end

