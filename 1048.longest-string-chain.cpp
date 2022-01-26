/*
 * @lc app=leetcode id=1048 lang=cpp
 *
 * [1048] Longest String Chain
 */

// @lc code=start
class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), [](string& a, string& b){
            return a.size() < b.size();
        });
        vector<int> dp(n, 1);
        int ans = 1;
        for (int i = 0; i < n; ++i)
        {
            for (int j = i - 1; j >= 0; --j)
            {
                if(isPredecessor(words[j], words[i]))
                {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }

    bool isPredecessor(string wa, string wb){
        if(wa.size() != wb.size()-1) return false;
        // if(wb.substr(1) == wa || wb.substr(0, wb.size()-1) == wa) return true;
        // for (int i = 1; i < wb.size()-1; ++i)
        // {
        //     if(wa == (wb.substr(0, i) + wb.substr(i+1))) return true;
        // }
        int i=0, j=0, count=0;
        while (i < wa.size() && j < wb.size())
        {
            if (wa[i] == wb[j])
            {
                ++i; ++j;
            }
            else
            {
                ++j;++count;
            }            
        }
        return count < 2;
    }
};
// @lc code=end

