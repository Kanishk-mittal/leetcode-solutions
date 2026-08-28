#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string shortestBeautifulSubstring(string s, int k)
    {
        string result = "";
        int n = s.size();

        for (int i = 0; i < n; i++)
        {
            int ones = 0;
            for (int j = i; j < n; j++)
            {
                if (s[j] == '1')
                    ones++;

                if (ones == k)
                {
                    string sub = s.substr(i, j - i + 1);
                    if (result == "" || sub.size() < result.size() ||
                        (sub.size() == result.size() && sub < result))
                    {
                        result = sub;
                    }
                    break;
                }
            }
        }
        return result;
    }
};

auto init = []()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();