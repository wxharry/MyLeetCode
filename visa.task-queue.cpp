#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int taskQueue(vector<int>& batchSize, vector<int>& processingTime, vector<int>& numTasks){
    int ans=0;
    for (int i = 0; i < numTasks.size(); i++)
    {
        int unit = numTasks[i]/batchSize[i];
        int remain = numTasks[i]%batchSize[i];
        if (remain)
        {
            ++unit;
        }
        ans = max(unit*processingTime[i], ans);
    }
    return ans;
}

int main()
{
    vector< vector < vector<int> > > testCases;
    vector<int>b({4, 3});
    vector<int>p({6, 5});
    vector<int>n({8, 8});
    testCases.push_back(vector<vector<int> >({b, p, n})); 

    testCases.push_back(vector<vector<int> >({{3, 2, 5, 7}, {5, 4, 10, 12}, {10, 6, 10, 5}})); 

    for (auto &testCase : testCases)
    {
        printf("%d\n",taskQueue(testCase[0], testCase[1], testCase[2]));
    }
    return 0;
}