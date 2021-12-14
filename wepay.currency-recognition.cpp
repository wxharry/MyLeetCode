#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// must consist of base-10 digits
// may contain thousands separators using ','. If it presents, must be present at each thousands increment
// must be prefixed by the currency symbol. support S, E, Y(Dollars, Euros, Yuan)
// negative and parentheses
// Dollar and Euro amounts may contain cents, represented to exactly 2 digits of precision
// if decimal is presented, cents must be specified
// yuan may not contain decimal points
// no leading zero, unless it has cents
// Zero is supported
// any other characters is invalid

class Solution
{
public:
    vector<string> testCases;
    bool isYuan=false;
    void generateTestCases()
    {
        vector<string> cases({"S450", "-E23", "(Y22400)", "S4,500.00", "E0.25", "cat", "L25", "S45,0", "(E350", "(-S3.50)", "Y120.00", "S-50", "S12.7c"});
        testCases = cases;
    }
    void test()
    {
        for (auto &testCase : testCases)
        {
            printf("%-10s: %d\n",testCase.c_str(), isCurrency(testCase));
            isYuan = false;
        }
    }
    string isNegative(string currency)
    {
        // if it starts with a (
        if (currency[0] == '(')
        {
            // there should not be a - inside of () and there should be a ) at the end
            if (currency[1] == '-' || currency[currency.size()-1] != ')')
            {
                cout << "- should be outside of ()" << endl;
                return "";
            }
            // we have done with the (), and continue to check what's inside.
            currency = currency.substr(1, currency.size()-2);
        }
        if (currency[0] == '-')
        {
            currency = currency.substr(1, currency.size()-1);
            if (currency[1] == '(')
            {
                if(currency[currency.size()-1] != ')')
                {
                    cout << ") is required" << endl;
                    return "";
                }
                currency = currency.substr(1, currency.size()-2);
            }
        }
        return currency;
    }
    string checkCurrency(string s)
    {
        // should start with YSE
        if (s[0] == 'Y' || s[0] == 'S' || s[0] == 'E')
        {
            // mark if currency type is yuan
            if (s[0] == 'Y')
            {
                isYuan = true;
            }
            return s.substr(1, s.size()-1);
        }
        cout << "wrong currency or no currency is given" << endl;
        return "";
    }
    string checkNumber(string s)
    {
        bool period = false;
        bool comma = false;
        string s_point;
        // if s is zero
        if (s == "0")
        {
            return s;
        }
        // if s contains a periods
        if (s.size() > 3 && s[s.size()-3] == '.')
        {
            period = true;
            // if s contains period, it should not be Yuan
            if (isYuan)
            {
                cout << "yuan cannot have cent" << endl;
                return "";
            }
        }
        // if s starts with 0, it should be like 0.xy
        if (s[0] == '0' && s[1] != '.')
        {
            cout << "should be 0." << endl;
            return "";
        }
        if (period)
        {
            if (!isdigit(s[s.size()-1]) || !isdigit(s[s.size()-2]))
            {
                cout << "invalid character appears" << endl;
                return "";
            }
            s = s.substr(0, s.size()-3);
        }
        if (s[s.size()-4] == ',')
        {
            comma=true;
        }
        for (int i = s.size() - 1; i >= 0; --i)
        {
            if (!isdigit(s[i]))
            {
                if (!(comma && !((s.size()-1-i)%3) && s[i] == ','))
                {
                    cout << "invalid character appears" << endl;
                    return "";
                }
            }
        }
        return s;   
    }
    bool isCurrency(string currency)
    {
        currency = isNegative(currency);
        if(currency == "") return false;
        currency  = checkCurrency(currency);
        if(currency == "") return false;
        currency = checkNumber(currency);
        if(currency == "") return false;
        return true;
    }
};

int main()
{
    Solution s;
    s.generateTestCases();
    s.test();
    return 0;
}