/*
 * @lc app=leetcode id=504 lang=cpp
 *
 * [504] Base 7
 */

// @lc code=start
class Solution {
public:
    string convertToBase7(int num) {
        if(num==0) return "0";
        string op = num < 0 ? "-": "";
        num = abs(num);
        string res="";
        while(num!=0){
            res = to_string(num%7) + res;
            num /=7;
        }
        return op+res;
    }
};
// @lc code=end

