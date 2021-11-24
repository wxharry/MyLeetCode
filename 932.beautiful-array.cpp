/*
 * @lc app=leetcode id=932 lang=cpp
 *
 * [932] Beautiful Array
 */

// @lc code=start
class Solution {
public:
    vector<int> beautifulArray(int n) {
        if(n==1) return vector<int> ({1});
        vector<int> res;
        int l = n/2;
        int r = n-n/2;
        vector<int> lvec = beautifulArray(l);
        vector<int> rvec = beautifulArray(r);
        for (auto &&item : lvec)
        {
            res.push_back(item*2);
        }
        for (auto &&item : rvec)
        {
            res.push_back(item*2-1);
        }
        return res;
        
    }
};
// @lc code=end

