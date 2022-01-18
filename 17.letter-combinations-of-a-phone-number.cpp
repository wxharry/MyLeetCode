/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
class Solution {
    vector<string> hmap = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
public:
    // iterative
    // vector<string> letterCombinations(string digits) {
    //     if(digits == "") return vector<string> ();
    //     vector<string> ans({""});
    //     for (auto &num : digits)
    //     {
    //         string str = hmap[num-'2'];
    //         vector<string> temp;
    //         for (int i = 0; i < ans.size(); ++i)
    //         {
    //             for (int j = 0; j < str.size(); ++j)
    //             {
    //                 temp.push_back(ans[i] + str[j]);
    //             }
    //         }
    //         swap(ans, temp);            
    //     }
    //     return ans;
    // }

    // recursive
    vector<string> re;
    vector<string> letterCombinations(string digits){
        if(digits == "") return vector<string>();
        dfs(digits, 0, "");
        return re;
    }

    void dfs(string digits, int level, string combi){
        if (level == digits.size())
        {
            re.push_back(combi);
            return;
        }
        for (auto &letter : hmap[digits[level]-'2'])
        {
            dfs(digits, level+1, combi + letter);
        }
        return;
    }
};
// @lc code=end

