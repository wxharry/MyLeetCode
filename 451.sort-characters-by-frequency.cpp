/*
 * @lc app=leetcode id=451 lang=cpp
 *
 * [451] Sort Characters By Frequency
 */

// @lc code=start
class Solution {
public:
    string frequencySort(string s) {
        unordered_map <char, int> dict;
        int max_count = 0;
        for (auto &&ch : s)
        {
            max_count = max(max_count, ++dict[ch]);
        }
        vector< vector < char> > bucket(max_count);
        for (auto &&i : dict)
        {
            bucket[i.second-1].push_back(i.first);
        }
        string result = "";
        for (int i = max_count-1; i >= 0; --i)
        {
            vector<char> t = bucket[i];
            for (int j = 0; j < t.size(); ++j)
            {
                for (int k = 0; k < i+1; ++k)
                {
                    result += t[j];
                }
                               
            }
            
        }
        return result;
        
        
    }
};
// @lc code=end

