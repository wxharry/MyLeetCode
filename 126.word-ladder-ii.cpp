/*
 * @lc app=leetcode id=126 lang=cpp
 *
 * [126] Word Ladder II
 */

// @lc code=start
class Solution {
public:


    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set <string> dict(wordList.begin(), wordList.end());
        unordered_set <string> visited;
        queue < vector<string> > q;
        vector<vector<string>> ans;
        q.push({beginWord});
        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                auto current_path = q.front();
                q.pop();
                auto last = current_path.back();
                for (size_t i = 0; i < last.size(); ++i)
                {
                    auto temp = last;
                    for (size_t j = 'a'; j <= 'z'; ++j)
                    {
                        last[i] = j;
                        if (dict.find(last) != dict.end())
                        {
                            auto new_path = current_path;
                            new_path.push_back(last);
                            visited.insert(last);
                            if (last == endWord)
                            {
                                ans.push_back(new_path);
                            }
                            else
                            {
                                q.push(new_path);
                            }
                        }
                    }
                    last = temp;
                }
            }
            for (auto &str : visited)
            {
                dict.erase(str);
            }
        }
        return ans;
    }
};
// @lc code=end

