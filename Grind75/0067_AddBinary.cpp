#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string addBinary(string a, string b)
    {
        int n = max(a.size(), b.size());

        a = string(n - a.size(), '0') + a;
        b = string(n - b.size(), '0') + b;

        string result(n, '0');
        char carry = '0';

        for (int i = n - 1; i >= 0; i--)
        {
            int sum = (a[i] - '0') + (b[i] - '0') + (carry - '0');
            result[i] = (sum % 2) + '0';
            carry = (sum / 2) + '0';
        }

        if (carry == '1')
            return "1" + result;

        return result;
    }
};

int main()
{
    Solution sol;
    string a = "11";
    string b = "1";
    cout << sol.addBinary(a, b);
    return 0;
}