#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int minRemovals(string s)
    {
        int balance = 0;
        int result = 0;
        for (char c : s)
        {
            if (!(c == '(' || c == ')'))
            {
                continue;
            }

            if (c == '(')
            {
                balance++;
            }
            else
            {
                balance--;
            }
            if (balance < 0)
            {
                result -= balance;
                balance = 0;
            }
        }
        return balance + result;
    }
    void build(set<string> &st, string &s, int i, int balance, int allowedRemovals, string &current)
    {
        if (balance < 0)
        {
            return;
        }

        if (i == s.size())
        {
            if (balance == 0)
            {
                st.insert(current);
            }
            return;
        }
        if (allowedRemovals && (s[i] == '(' || s[i] == ')'))
        {
            build(st, s, i + 1, balance, allowedRemovals - 1, current);
        }
        if (s[i] == '(')
        {
            balance++;
        }
        if (s[i] == ')')
        {
            balance--;
        }
        current.push_back(s[i]);
        build(st, s, i + 1, balance, allowedRemovals, current);
        current.pop_back();
    }

public:
    vector<string> removeInvalidParentheses(string s)
    {
        int allowed_Removals = minRemovals(s);
        set<string> st;
        string current = "";
        build(st, s, 0, 0, allowed_Removals, current);
        return vector<string>(st.begin(), st.end());
    }
};

auto init = []()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<string> resutl = sol.removeInvalidParentheses("()())()");
    return 0;
}
