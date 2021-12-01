#include <iostream>
#include <vector>
#include <string>

using namespace std;

string compression(string message){
    if (message=="")
    {
        return "";
    }
    string ans="";
    int i=0, count=0;
    while (i < message.size())
    {
        char ch = message[i];
        string str(1, ch);
        ans += str;
        count=0;
        int j=i;
        while (j < message.size())
        {
            if (message[j] == ch)
            {
                ++count;
            }
            else
            {
                break;
            }
            ++j;
        }
        if (count > 1)
        {
            ans += to_string(count);
        }
        i = j;
    }
    return ans;
}

int	main(int argc, char **argv)
{
    vector<string> testCases;
    testCases.push_back("abaasass"); //aba2sas2
    testCases.push_back("abc"); //abc
    testCases.push_back("abaabbbc"); //aba2b3c
    testCases.push_back("a"); //a
    testCases.push_back("aaaa"); //a4
    testCases.push_back(""); //
    for (auto &testCase : testCases)
    {
        printf("%s\n", compression(testCase).c_str());
    }
    
    return 0;
}
