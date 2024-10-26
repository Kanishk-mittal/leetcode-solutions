# include <iostream>
# include <vector>
# include <unordered_map>

using namespace std;

class Solution
{
private:
    unordered_map<char, string> phoneMap = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}};
    void backtrack(vector<string>& result, string& digits, int index, string& current)
    {
        if (index == digits.size())
        {
            result.push_back(current);
            return;
        }
        char digit = digits[index];
        string letters = phoneMap[digit];
        for (auto ch : letters)
        {
            current.push_back(ch);
            backtrack(result, digits, index + 1, current);
            current.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> result;
        if (digits.empty())
        {
            return result;
        }
        string current;
        backtrack(result, digits, 0, current);
        return result;
    }
};