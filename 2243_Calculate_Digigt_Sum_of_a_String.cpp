#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    string dSum(string s, int idx, int k)
    {
        int sum = 0;
        for (int i = idx; i < idx + k && i < s.size(); i++)
        {
            sum += (s[i] - '0');
        }
        return to_string(sum);
    }

public:
    string digitSum(string s, int k)
    {
        if (s.size() <= k)
        {
            return s;
        }
        string temp = "";
        for (int i = 0; i < s.size(); i += k)
        {
            temp += dSum(s, i, k);
        }
        return digitSum(temp, k);
    }
};

auto init = []()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();