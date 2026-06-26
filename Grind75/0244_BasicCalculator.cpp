#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<pair<string, bool>> getToken(string s)
    {
        string token = "";
        vector<pair<string, bool>> result;
        for (char c : s)
        {
            if (' ' == c)
            {
                continue;
            }
            if ('+' == c || '-' == c || '(' == c || ')' == c)
            {
                if (token.size())
                {
                    result.push_back({token, true});
                    token = "";
                }
                token.push_back(c);
                result.push_back({token, false});
                token.pop_back();
            }
            else
            {
                token.push_back(c);
            }
        }
        if (token.size())
        {
            result.push_back({token, true});
        }
        return result;
    }

public:
    int calculate(string s)
    {
        vector<pair<string, bool>> token = getToken(s);
        long long total = 0;
        int sign = 1;
        stack<pair<long long, int>> st;
        for (pair<string, bool> t : token)
        {
            if (t.second)
            {
                total += sign * stoll(t.first);
            }
            else if ("+" == t.first)
            {
                sign = 1;
            }
            else if ("-" == t.first)
            {
                sign = -1;
            }
            else if ("(" == t.first)
            {
                st.push({total, sign});
                total = 0;
                sign = 1;
            }
            else if (")" == t.first)
            {
                total *= st.top().second;
                total += st.top().first;
                st.pop();
            }
        }
        return total;
    }
};

int main()
{
    Solution sol;
    cout << sol.calculate("-2147483648");
    return 0;
}