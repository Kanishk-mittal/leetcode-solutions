# include <iostream>
# include <vector>
# include <stack>
# include <string>
# include <cstdlib>
using namespace std;

class Solution
{
private:
    string calculate(string num1, string num2, string optr)
    {
        int n1 = stoi(num1);
        int n2 = stoi(num2);
        if (optr == "+")
            return to_string(n1 + n2);
        if (optr == "-")
            return to_string(n1 - n2);
        if (optr == "*")
            return to_string(n1 * n2);
        if (optr == "/")
            return to_string(n1 / n2);
        return "";
    }

public:
    int evalRPN(vector<string> &tokens)
    {
        stack<string> values;
        for (string token : tokens)
        {
            if (token == "+" || token == "-" || token == "*" || token == "/")
            {
                string num2 = values.top();
                values.pop();
                string num1 = values.top();
                values.pop();
                values.push(calculate(num1, num2, token));
            }
            else
            {
                values.push(token);
            }
        }
        return stoi(values.top());
    }
};