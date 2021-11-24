/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 */

// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int> dp(n, 0);
        dp[n-1] = 0;
        for (int i = n - 2; i >= 0; --i)
        {
            if (temperatures[i] < temperatures[i+1])
            {
                dp[i] = 1;
            }
            else
            {
                int j=i+1;
                while (j < n)
                {
                    if (temperatures[i]<temperatures[j])
                    {
                        dp[i]+=1;
                        break;
                    }
                    else
                    {
                        if (dp[j]==0)
                        {
                            dp[i]=0;
                            break;
                        }
                       dp[i]+=dp[j];
                       j=j+dp[j];
                    }
                }
                
            }
            
            
        }
        return dp;
    }
};
// @lc code=end

