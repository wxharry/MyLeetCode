/*
 * @lc app=leetcode id=470 lang=cpp
 *
 * [470] Implement Rand10() Using Rand7()
 */

// @lc code=start
// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
    int i,j;
    while( (i = rand7()) > 6);  // P(i is even) = P(i is odd) = 0.5
    while( (j = rand7()) > 5);  // P(j==1) = P(j==2) = P(j==3) = P(j==4) = P(j==5) = 0.2
    return (i&1) ? j : j+5;
        
    }
};
// @lc code=end

