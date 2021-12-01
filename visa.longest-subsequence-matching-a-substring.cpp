#include <iostream>
#include <string>
#include <vector>
using namespace std;

int FindLength(string x, string y){
    int xlen = x.size(), ylen=y.size();
    int ans=0;
    if (!xlen||!ylen)
    {
        return ans;
    }
    int start=0, end=1; //include left; exclude right
    while (end < ylen+1)
    {
        int si=start;
        vector<int> dp(xlen+1, 0);
        for (int i = 1; i < xlen+1; ++i)
        {
            if (si < end && x[i-1] == y[si])
            {
                dp[i] = dp[i-1] + 1;
                ++si;
            }
            else
            {
                dp[i] = dp[i-1];
            }
        }
        if (dp[xlen] == (end-start)) //find subsequence
        {
            ans = dp[xlen];
            ++end;
        }
        else
        {
            ++start;
            ++end;
        }
    }
    return ans;
}

int	main()
{
    vector < vector<string> > testCases;
    testCases.push_back(vector<string>({"abcd", "abdc"})); 
    testCases.push_back(vector<string>({"hackerranks", "hackers"})); 
    testCases.push_back(vector<string>({"abc", "aedace"})); 
    for (auto &testCase : testCases)
    {
        printf("%d\n",FindLength(testCase[0], testCase[1]));
    }
    return 0;
}
