/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start
class Solution {
    vector<string> re;
public:
    vector<string> generateParenthesis(int n) {
        backtracking(n, 0, 0, "");
        return re;
    }

    void backtracking(int n, int left, int right, string combi){
        if(combi.size() == n*2){
            re.push_back(combi);
            return;
        }
        if (left < n)
        {
            backtracking(n, left+1, right, combi+'(');
        }
        if(right < left){
            backtracking(n, left, right+1, combi+')');
        }
    }
};
// @lc code=end

