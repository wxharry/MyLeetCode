/*
 * @lc app=leetcode id=524 lang=cpp
 *
 * [524] Longest Word in Dictionary through Deleting
 */

// @lc code=start
class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        int si=0, ri=-1, wi=0, longest=0;
        bool flag;
        string r;
        string w;
        for (int i = 0; i < dictionary.size(); ++i)
        {
            w = dictionary[i];
            if (w.size() < longest)
            {
                continue;
            }            
            si=0;wi=0;
            while (wi < w.size() && si < s.size())
            {
                if(w[wi] != s[si]){
                    ++si;
                }
                else
                {
                    ++si; ++wi;
                }
            }
  
            if (wi == w.size())
            {
                if (w.size() > r.size() || (w.size() == r.size() && w < r))
                {
                    r = w;
                }                
            }
        }
        return r;
    }
};
// @lc code=end

