/*
 * @lc app=leetcode id=135 lang=cpp
 *
 * [135] Candy
 */

// @lc code=start
class Solution {
public:
    int candy(vector<int>& ratings) {
        int size = ratings.size();
        vector<int> div(size, 1);
        for (int i = size-2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i+1]&& div[i] <= div[i+1]) // condition after && is useless, it is here for understanding only
            {
                div[i]  = div[i+1] +1;
            }
            
        }
        for (int i = 1; i < size; i++)
        {
            if (ratings[i] > ratings[i-1] && div[i] <= div[i-1])
            {
                div[i] = div[i-1] +1;
            }
            
        }
        return accumulate(div.begin(), div.end(), 0);
    }
};
// @lc code=end

