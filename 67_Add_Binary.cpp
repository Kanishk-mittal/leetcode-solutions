# include <iostream>

using namespace std;

class Solution
{
public:
    string addBinary(string a, string b)
    {
        string res;
        int i = a.size() - 1, j = b.size() - 1, carry = 0;
        while (i >= 0 || j >= 0 || carry)
        {
            carry += i >= 0 ? a[i--] - '0' : 0;
            carry += j >= 0 ? b[j--] - '0' : 0;
            res = to_string(carry % 2) + res;
            carry /= 2;
        }
        return res;
    }
};