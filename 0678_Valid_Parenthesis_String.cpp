#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool check(vector<vector<int>> &memo, string &s, int i, int count)
    {
        if (memo[i][count] != -1)
        {
            return memo[i][count];
        }

        if (i == s.size())
        {
            return count == 0;
        }
        if (s[i] == '(')
        {
            return memo[i][count] = check(memo, s, i + 1, count + 1);
        }
        if (s[i] == ')')
        {
            if (count > 0)
            {
                return memo[i][count] = check(memo, s, i + 1, count - 1);
            }
            return false;
        }
        bool result = check(memo, s, i + 1, count); // as empty string
        result |= check(memo, s, i + 1, count + 1); // as (
        if (count > 0)
        {
            result |= check(memo, s, i + 1, count - 1);
        }
        return memo[i][count] = result;
    }

public:
    bool checkValidString(string s)
    {
        int n = s.size();
        vector<vector<int>> memo(n + 1, vector<int>(n + 1, -1));
        return check(memo, s, 0, 0);
    }
};

auto init = []()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();