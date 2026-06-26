#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    string solve(string a, string b, string op)
    {
        int va = stoi(a);
        int vb = stoi(b);
        if ("+" == op)
        {
            return to_string(va + vb);
        }
        if ("-" == op)
        {
            return to_string(va - vb);
        }
        if ("*" == op)
        {
            return to_string(va * vb);
        }
        if ("/" == op)
        {
            return to_string(va / vb);
        }
        return "-1"; // just to avoid error
    }
    bool isOp(string op)
    {
        return "+" == op || "-" == op || "*" == op || "/" == op;
    }

public:
    int evalRPN(vector<string> &tokens)
    {
        stack<string> s;
        int n = tokens.size();
        for (string t : tokens)
        {
            if (!isOp(t))
            {
                s.push(t);
            }
            else
            {
                string b = s.top();
                s.pop();
                string a = s.top();
                s.pop();
                s.push(solve(a, b, t));
            }
        }
        return s.top();
    }
};

int main()
{
    Solution sol;
    return 0;
}