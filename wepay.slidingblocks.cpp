#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<vector<int> > > testCases;
    void generateTestCases()
    {
        vector<vector<vector<int> > > cases;
        cases.push_back(vector<vector<int> >({{1, 6, 3}, {8, 7, 2}, {4, 0, 5}}));
        // cases.push_back(vector<vector<int> >({{1, 6, 3}, {8, 7, 2}, {4, 0, 5}}));
        testCases = cases;
    }
    void test()
    {
        for (auto &testCase : testCases)
        {
            printf("%d\n", slidingBlocks(testCase));
        }
    }
    int slidingBlocks(vector< vector<int> > rect)
    {
        
    }
};

int main()
{
    Solution s;
    s.generateTestCases();
    s.test();
    return 0;
}