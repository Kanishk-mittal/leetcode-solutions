#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool isCompliment(char b1, char b2)
    {
        return (b1 == '(' && b2 == ')') ||
               (b1 == '[' && b2 == ']') ||
               (b1 == '{' && b2 == '}');
    }

public:
    bool isValid(string s)
    {
        stack<char> st;

        for (char c : s)
        {
            if (st.empty())
            {
                st.push(c);
                continue;
            }

            if (isCompliment(st.top(), c))
            {
                st.pop();
            }
            else
            {
                st.push(c);
            }
        }

        return st.empty();
    }
};

int main()
{
    Solution sol;
    return 0;
}