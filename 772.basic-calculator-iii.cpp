#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// Implement a basic calculator to evaluate a simple expression string.

// The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

// The expression string contains only non-negative integers, +, -, *, / operators , open ( and closing parentheses ) and empty spaces . The integer division should truncate toward zero.

// You may assume that the given expression is always valid. All intermediate results will be in the range of [-2147483648, 2147483647].

int basicCalc(string s){
    
    return -1;
}

int	main(int argc, char **argv)
{
    vector<vector<string> > testCases;
    testCases.push_back(vector<string>({"1 + 1"})); // 2
    testCases.push_back(vector<string>({" 6-4 / 2"})); // 4
    testCases.push_back(vector<string>({"2*(5+5*2)/3+(6/2+8)"})); // 21
    testCases.push_back(vector<string>({"(2+6* 3+5- (3*14/7+2)*5)+3"})); // -12

    for (auto &testCase : testCases)
    {
        printf("%d\n", basicCalc(testCase[0]));
    }
    return 0;
}

