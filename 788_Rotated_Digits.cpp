#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    string digitMirror(char n)
    {
        if ('0' == n || '8' == n || '1' == n)
        {
            return string(1, n);
        }
        else if ('2' == n)
        {
            return "5";
        }
        else if ('5' == n)
        {
            return "2";
        }
        else if ('9' == n)
        {
            return "6";
        }
        else if ('6' == n)
        {
            return "9";
        }
        else
        {
            return "-";
        }
    }
    string numMirror(int n)
    {
        string ns = to_string(n);
        string result = "";
        for (char c : ns)
        {
            string mirror = digitMirror(c);
            if ("-" == mirror)
            {
                return "-";
            }
            else
            {
                result += mirror;
            }
        }
        return to_string(n) == result ? "-" : result;
    }

public:
    int rotatedDigits(int n)
    {
        int count = 0;
        for (int i = 2; i <= n; i++)
        {
            string mirror = numMirror(i);
            if ("-" != mirror)
            {
                count++;
            }
        }
        return count;
    }
};

int main()
{
    Solution sol;
    cout << sol.rotatedDigits(10);
    return 0;
}