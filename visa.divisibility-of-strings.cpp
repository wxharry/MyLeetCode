#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string findDivider(string s){
    int start=0, end=1;
    while (end < s.size())
    {
        if (s[start] == s[end])
        {
            ++start;
            ++end;
        }
        else
        {
            start = 0;
            ++end;
        }
    }
    return s.substr(0, end-start);
}

int lengthOfMinDivString(string s, string t){
    if (s == t)
    {
        return t.size();
    }
    if (!s.size()||!t.size())
    {
        return -1;
    }
    string cont=t;
    while (cont.size() < s.size())
    {
        cont+=t;
        if (cont == s)
        {
            string f=findDivider(t);
            return f.size();
        }
    }
    return -1;
}

int	main(int argc, char **argv)
{
    vector<vector<string> > testCases;
    testCases.push_back(vector<string>({"bcdbcdbcdbcd", "bcdbcd"})); // 3
    testCases.push_back(vector<string>({"bcdbcdbcd", "bcdbcd"})); // -1
    testCases.push_back(vector<string>({"aaaaaa", "a"})); // 1
    testCases.push_back(vector<string>({"aaaaaa", "aa"})); // 1
    testCases.push_back(vector<string>({"abcabdabcabd", "abcabd"})); // 6
    testCases.push_back(vector<string>({"abcabcabcabcabcabc", "abcabcabc"})); // 3

    for (auto &testCase : testCases)
    {
        printf("%d\n", lengthOfMinDivString(testCase[0], testCase[1]));
    }
    return 0;
}

