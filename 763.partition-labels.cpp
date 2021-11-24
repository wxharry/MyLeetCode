/*
 * @lc app=leetcode id=763 lang=cpp
 *
 * [763] Partition Labels
 */

// @lc code=start
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> v(128, 0);
        vector<int> r;
        for (int i = 0; i < s.size(); ++i)
        {
            v[s[i]] = i;
        }
        int end = 0;
        int start  = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            end  = max(v[s[i]], end);
            if (end == i)
            {
                r.push_back(end-start+1);
                start = end + 1;
            }

            
        }
        return r;
        
                
    }
};
// @lc code=end

