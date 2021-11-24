/*
 * @lc app=leetcode id=528 lang=cpp
 *
 * [528] Random Pick with Weight
 */

// @lc code=start
class Solution {
public:
    vector<int> weights;
    Solution(vector<int>& w) {
        weights=w;
    }
    
    int pickIndex() {
        int sum = accumulate(weights.begin(), weights.end(), 0);
        int p = random()%sum;
        int foo=0;
        for (int i = 0; i < weights.size(); ++i)
        {
            foo += weights[i];
            if (foo > p)
            {
                return i;
            }
        }
        return weights.size() -1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
// @lc code=end

