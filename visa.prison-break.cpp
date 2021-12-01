#include <iostream>
#include <vector>

using namespace std;

int prisonBreak(int m, int n, vector<int>& horizon, vector<int>& vertical){
    int h=horizon.size(), v=vertical.size();
    int hi=0, vi=0;
    int maxh=1, maxv=1;
    vector<int> dp(m+1, 1);
    for (int i = 1; i < m+1; ++i)
    {
        if (i == horizon[hi])
        {
            dp[i] = dp[i-1]+1;
            maxh = max(maxh, dp[i]);
            ++hi;
        }
        else
        {
            dp[i] = 1;
        }
    }
    vector<int> dp2(m+1, 1);
    for (int i = 1; i < n+1; ++i)
    {
        if (i == vertical[vi])
        {
            dp2[i] = dp2[i-1]+1;
            maxv = max(maxv, dp2[i]);
            ++vi;
        }
        else
        {
            dp2[i] = 1;
        }
    }
    return maxh*maxv;
}

int	main(int argc, char **argv)
{
    vector< vector < vector <int> > > testCases;
    testCases.push_back(vector< vector< int> >({{6, 6}, {4},{2}})); //4
    testCases.push_back(vector< vector< int> >({{3, 3},{2}, {2}})); //4
    testCases.push_back(vector< vector< int> >({{2, 2},{1}, {2}})); //4
    testCases.push_back(vector< vector< int> >({{3, 2},{1,2,3}, {1,2}})); //12
    for (auto &testCase : testCases)
    {
        printf("%d\n", prisonBreak(testCase[0][0], testCase[0][1], testCase[1], testCase[2]));
    }
    return 0;
}
