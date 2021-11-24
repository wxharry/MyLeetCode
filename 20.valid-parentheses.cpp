/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (auto &ch : s)
        {
            switch (ch)
            {
            case '(':
            case '[':
            case '{':
                st.push(ch);
                break;
            case ')':
                if (st.empty() || st.top() != '(') return false;
                st.pop();
                break;
            case ']':
                if (st.empty() || st.top() != '[') return false;
                st.pop();
                break;
            case '}':
                if (st.empty() || st.top() != '{') return false;
                st.pop();
                break;            
            }
        }
        return st.empty();
    }
};
// @lc code=end

