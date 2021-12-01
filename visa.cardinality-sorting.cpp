#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector<int> cardinalitySorting(vector<int>& nums){
    sort(nums.begin(), nums.end(), [](int a, int b){
        int counta=0, countb=0;
        while (a)
        {
            counta += a&1;
            a >>= 1;
        }
        while (b)
        {
            countb += b&1;
            b >>=1;
        }
        return counta < countb;
    });    
    return nums;
}

int	main(int argc, char **argv)
{
    vector<vector<int> > testCases;
    testCases.push_back(vector<int>({1, 2, 3, 4})); // 1 2 4 3
    testCases.push_back(vector<int>({1, 5, 6, 7, 8})); // 1 8 5 6 7

    for (auto &testCase : testCases)
    {
        vector<int> res = cardinalitySorting(testCase);
        for (auto &r : res)
        {
            printf("%d ", r);
        }
        printf("\n");
    }
    return 0;
}

