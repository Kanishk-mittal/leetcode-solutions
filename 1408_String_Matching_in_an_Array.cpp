# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

class Solution
{
public:
    vector<string> stringMatching(vector<string> &words)
    {
        // Sort words by length
        sort(words.begin(), words.end(), [](const string &a, const string &b)
             { return a.size() < b.size(); });

        vector<string> res;
        for (int i = 0; i < words.size(); i++)
        {
            for (int j = i + 1; j < words.size(); j++)
            {
                // If words[i] is a substring of words[j]
                if (words[j].find(words[i]) != string::npos)
                {
                    res.push_back(words[i]);
                    break; // Move to the next word[i]
                }
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}