/*
 * @lc app=leetcode id=202 lang=cpp
 *
 * [202] Happy Number
 */

// @lc code=start
class Solution
{
public:
    bool isHappy(int n)
    {
        unordered_map<int, int> temp;
        while (n!=1)
        {
            cout << n << endl;
            if (temp[n] == 0)
            {
                ++ temp[n];
            }
            else
            {
                return false;
            }
            int sum=0;
            while (n != 0)
            {
                sum += n%10 * (n%10);
                n /= 10;             
            }
            n = sum;    
        }
        return true;
    }
};
// @lc code=end
