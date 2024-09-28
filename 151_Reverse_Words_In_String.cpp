# include <iostream>
# include <vector>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        vector<string> words;
        string word;
        for (char c : s)
        {
            if (c == ' ')
            {
                if (!word.empty())
                {
                    words.push_back(word);
                    word.clear();
                }
            }
            else
            {
                word += c;
            }
        }
        if (!word.empty())
        {
            words.push_back(word);
        }
        reverse(words.begin(), words.end());
        string result;
        for (size_t i = 0; i < words.size(); ++i)
        {
            if (i > 0)
            {
                result += " ";
            }
            result += words[i];
        }

        return result;
    }
};