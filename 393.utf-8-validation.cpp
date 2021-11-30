/*
 * @lc app=leetcode id=393 lang=cpp
 *
 * [393] UTF-8 Validation
 */

// @lc code=start
class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int check=0;
        for (int i = 0; i < data.size(); i++)
        {
            int e=data[i];
            if (check)
            {
                if (e >> 6 == 0b10)
                {
                    --check;
                    continue;
                }
                else
                {
                    return false;   
                }
            }
            if (e >> 7 == 0 ) continue;
            else if ((e >> 5) == 0b110)
            {
                check=1;   
            }
            else if ((e >> 4) == 0b1110)
            {
                check=2;
            }
            else if ((e >> 3) == 0b11110)
            {
                check=3;
            }
            else
            {
                return false;
            }
            
        }
        return check?false: true;
    }
};
// @lc code=end

