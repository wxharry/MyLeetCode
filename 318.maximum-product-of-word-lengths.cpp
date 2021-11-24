/*
 * @lc app=leetcode id=318 lang=cpp
 *
 * [318] Maximum Product of Word Lengths
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<string>& words) {
        unordered_map<int, int> dict;
        int ans = 0;
        for (auto &&word : words)
        {
            int mask=0, n=word.size();
            for (auto &&c : word)
            {
                mask |= 1 << (c-'a');
            }
            dict[mask] = max(dict[mask], n);
            // cout << mask << " " << dict[mask] << endl;
            for (auto &&[k,v] : dict)
            {
                if (!(k & mask))
                {
                    ans = max(ans, n * v);
                }
            }

        }
        return ans;
    }
};
// @lc code=end

