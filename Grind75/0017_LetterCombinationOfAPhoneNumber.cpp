#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<string> result;
    vector<string> mapping = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void backtrack(string digits, int index, string current)
    {
        if (index == digits.size())
        {
            result.push_back(current);
            return;
        }
        int digit = digits[index] - '0';
        for (char c : mapping[digit])
        {
            backtrack(digits, index + 1, current + c);
        }
    }

public:
    vector<string> letterCombinations(string digits)
    {
        if (digits.empty())
        {
            return {};
        }
        backtrack(digits, 0, "");
        return result;
    }
};

int main()
{
    Solution sol;
    return 0;
}