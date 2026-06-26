#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    char processStr(string s, long long k)
    {
        long long l = 0;
        for (char c : s)
        {
            if (c == '*')
            {
                l = max(0LL, l - 1);
            }
            else if (c == '#')
            {
                l *= 2;
            }
            else if (c == '%')
            {
                continue;
            }
            else
            {
                l++;
            }
        }
        if (k >= l)
        {
            return '.';
        }
        int n = s.size();
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == '*')
            {
                l++;
            }
            else if (s[i] == '#')
            {
                l /= 2;
                if (k >= l)
                {
                    k -= l;
                }
            }
            else if (s[i] == '%')
            {
                k = l - 1 - k;
            }
            else
            {
                if (k == l - 1)
                {
                    return s[i];
                }
                l--;
            }
        }
        return '.';
    }
};

int main()
{
    Solution sol;
    return 0;
}

/*
If the letter is a lowercase English letter append it to result.
A '*' removes the last character from result, if it exists.
A '#' duplicates the current result and appends it to itself.
A '%' reverses the current result.
*/