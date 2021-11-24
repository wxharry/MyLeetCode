/*
 * @lc app=leetcode id=241 lang=cpp
 *
 * [241] Different Ways to Add Parentheses
 */

// @lc code=start
class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        int n = expression.size();
        vector<int> res;
        for (int i = 0; i < n; ++i)
        {
            char op = expression[i];
            if(op >= '0' && op <= '9') continue;
            vector<int> lvector = diffWaysToCompute(expression.substr(0, i));
            vector<int> rvector = diffWaysToCompute(expression.substr(i+1, n));
            for (auto &l : lvector)
            {
                for (auto &r : rvector)
                {
                    switch (op)
                    {
                    case '+':
                        res.push_back(l+r);
                        break;
                    case '-':
                        res.push_back(l-r);
                        break;                    
                    case '*':
                        res.push_back(l*r);
                        break;
                    }
                    
                }
                
            }
            
        }
        if(res.empty()) return vector<int>({stoi(expression)});
        return res;
    }
};
// @lc code=end

