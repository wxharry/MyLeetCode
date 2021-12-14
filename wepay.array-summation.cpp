#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// test if element in test can be computed by any two of elements in inputs

class Solution
{
public:
    vector<vector <vector<int> > > testCases;
    bool isYuan=false;
    void generateTestCases()
    {
        vector<vector <vector<int> > > cases({{{-1, 8, 3}, {1, 2, 4}}, {{9, 6, 12}, {1, 2, 3}}});
        testCases = cases;
    }
    void test()
    {
        for (auto &testCase : testCases)
        {
            for (auto &c : testCase[0])
            {
                cout << c << ' ';
            }
            cout << "\t";
            for (auto &c : testCase[1])
            {
                cout << c << ' ';
            }
            cout << "\t";
            printf("%d\n", testArray(testCase[0], testCase[1]));
        }
    }
    bool testArray(vector<int> inputs, vector<int> test)
    {
        for (int i = 0; i < inputs.size()-1; i++)
        {
            for (int j = i+1; j < inputs.size(); j++)
            {
                for (auto &x : test)
                {
                    if (inputs[i] + inputs[j] == x)
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

int main()
{
    Solution s;
    s.generateTestCases();
    s.test();
    return 0;
}