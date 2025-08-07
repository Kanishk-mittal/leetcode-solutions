#include <iostream>
#include <vector>

using namespace std;
class Solution
{
private:
    string justify_center(const string &ipt, int maxWidth)
    {
        vector<string> words;
        string temp;
        for (char chr : ipt)
        {
            if (chr == ' ')
            {
                if (!temp.empty())
                {
                    words.push_back(temp);
                    temp.clear();
                }
            }
            else
            {
                temp += chr;
            }
        }
        if (!temp.empty())
        {
            words.push_back(temp);
        }

        int total_chars = 0;
        for (const string &word : words)
        {
            total_chars += word.size();
        }
        int remaining_spaces = maxWidth - total_chars;
        int space_count = words.size() - 1;
        vector<string> spaces(space_count, "");
        for (int i = 0; i < remaining_spaces; i++)
        {
            spaces[i % space_count] += " ";
        }
        string result = words[0];
        for (int i = 0; i < space_count; i++)
        {
            result += spaces[i] + words[i + 1];
        }
        return result;
    }

    string justify_left(const string &ipt, int maxWidth)
    {
        return ipt + string(maxWidth - ipt.size(), ' ');
    }

    int space_count(const string &ipt)
    {
        return count(ipt.begin(), ipt.end(), ' ');
    }

public:
    vector<string> fullJustify(vector<string> &words, int maxWidth)
    {
        vector<string> result;
        string temp = words[0];
        for (int i = 1; i < words.size(); i++)
        {
            if (temp.size() + words[i].size() + 1 <= maxWidth)
            {
                temp += " " + words[i];
            }
            else
            {
                result.push_back(temp);
                temp = words[i];
            }
        }
        result.push_back(temp);
        for (int i = 0; i < result.size() - 1; i++)
        {
            if (space_count(result[i]) == 0)
            {
                result[i] = justify_left(result[i], maxWidth);
            }
            else
            {
                result[i] = justify_center(result[i], maxWidth);
            }
        }
        result.back() = justify_left(result.back(), maxWidth);
        return result;
    }
};