/*
 * @lc app=leetcode id=127 lang=cpp
 *
 * [127] Word Ladder
 */

// @lc code=start
class Solution {
public:
    // dfs + backtracking encounters time limit exceeded
    // we are using bfs
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        int minLadder = wordList.size()+1;
        int path=0;
        deque<string> dq;
        dq.push_back(beginWord);
        while (!dq.empty())
        {
            ++ path;
            int count = dq.size();
            for (int i = 0; i < count; ++i)
            {
                string word = dq.front();
                dq.pop_front();
                for (int j = 0; j < word.size(); ++j)
                {
                    char ch = word[j];
                    for (int k = 'a'; k <= 'z'; ++k)
                    {
                        word[j] = k;
                        if(!wordSet.count(word)) continue;
                        if(word == endWord) return path+1;
                        wordSet.erase(word);
                        dq.push_back(word);
                    }
                    word[j] = ch;
                }
            }
        }
        return 0;
    }
};
// @lc code=end

